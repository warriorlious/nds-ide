/************************************************************************
 *
 *                    File downloader for Nintendo DS
 *                   ---------------------------------
 *           (C) Copyright 2009 by Minsuk Lee, Seoul, Korea
 *                      All Rights Reserved.
 *
 ************************************************************************/

/* FILE        : dshdown.c
 *
 * Description : File Downloader to Nintendo DS
 *
 * Created - 2009-12-27 by Minsuk Lee
 * Revised - 2009-XX-XX 
 *         - 2009-XX-XX
 * Read    - 2009-XX-XX
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include <pthread.h>
#include <time.h>
#include <signal.h>

#include "download.h"

static int data_socket;
static int clnt_socket;

static struct header FHeader;
static struct response FResp;
static struct stat statinfo;
int Channel; // 't' : tcp, 's' : Serial, 'u' : USB
int Port; // TCP port number for 't'
unsigned char tmp_port[MAX_FILE_NAME_LEN]; //port number to string
int filelength;
int filesend();

#define CHANNEL_TCP     't'
#define CHANNEL_SERIAL  's'
#define CHANNEL_USB     'u'

#define  MAX_SIZE 2048

void disconnect_nds() {
	close(data_socket);
	close(clnt_socket);
}

int connect_pc() {

	struct sockaddr_in nds_sin;
	struct sockaddr_in nds_cos;
	int size;

	disconnect_nds();

	if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		fprintf(stderr, "Error at socket(): %d\n", data_socket);
		return -1;
	}

	memset(&nds_sin, 0, sizeof(nds_sin));
	nds_sin.sin_family = AF_INET;
	nds_sin.sin_addr.s_addr = htonl(INADDR_ANY);
	nds_sin.sin_port = htons(Port + 1);

	if (bind(data_socket, (struct sockaddr*) &nds_sin, sizeof(nds_sin)) == -1) {
		fprintf(stderr, "bind() PC error! - port %d\n", Port);
		return 1;
	}

	if (listen(data_socket, 15) == -1) {
		fprintf(stderr, "listen() error!\n");
		return 1;
	}

	size = sizeof(nds_cos);

	clnt_socket = accept(data_socket, (struct sockaddr *) &nds_cos, &size);

	if (clnt_socket == -1) {
		fprintf(stderr, "accept() to PC error!\n");
		close(data_socket);
		close(clnt_socket);
		exit(1);
	}

	return 0;
}

int connect_nds() {

	struct sockaddr_in nds_sin;
	struct sockaddr_in nds_cos;
	int size;

	disconnect_nds();

	if ((clnt_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
		fprintf(stderr, "Error at socket(): %d\n", data_socket);
		return -1;
	}

	memset(&nds_sin, 0, sizeof(nds_sin));
	nds_sin.sin_family = AF_INET;
	nds_sin.sin_addr.s_addr = htonl(INADDR_ANY);
	nds_sin.sin_port = htons(Port);

	if (bind(clnt_socket, (struct sockaddr*) &nds_sin, sizeof(nds_sin)) == -1) {
		fprintf(stderr, "bind() DS error! - port %d\n", Port);
		return 1;
	}

	//	printf("bind succes\n");

	if (listen(clnt_socket, 15) == -1) {
		fprintf(stderr, "listen() error!\n");
		return 1;
	}
	//	printf("listen succes\n");
	size = sizeof(nds_cos);
	data_socket = accept(clnt_socket, (struct sockaddr *) &nds_cos, &size);

	if (data_socket == -1) {
		fprintf(stderr, "accept() to DS 2nd fail\n");
		disconnect_nds();
	}
	return 0;
}

int send_data(unsigned char *buf, int len) {
	int ret;
	int size, count = len;

	loop: while (count) {

		if ((size = send(data_socket, buf, count, 0)) <= 0) {
			fprintf(stderr, "TCP Send Error\n");
			return -1; // Error
		}

		buf += size;
		count -= size;
	}
	return len;
}

int recv_data(unsigned char *buf, int count) {
	int size, tread = 0;

	while (count) {

		if ((size = recv(data_socket, buf, count, 0)) < 0) {
			fprintf(stderr, "TCP Recv Error\n");
			return -1; // Error
		}

		if (size == 0)
			break;

		buf += size;
		count -= size;
		tread += size;
	}
	return tread;
}

int recv_data_byte(unsigned char *buf, int count) {
	int read_size = 1;
	int size, tread = 0;

	while (count) {

		if ((size = recv(data_socket, buf, count, 0)) < 0) {
			fprintf(stderr, "TCP Recv Error\n");
			return -1; // Error
		}

		if (size == 1) {
			buf += read_size;
			count -= read_size;
			tread += read_size;
		}
	}
	return tread;
}

/* Something wrong in this function,
 this function just kills himself after sleep(). not the problematic child process.
 this function should be threaded by parent with the child pid */

void *t_function() {

	pid_t mypid;
	mypid = getpid();
	sleep(300);

	disconnect_nds();
	fprintf(stderr, "\nProcess kill : Time Over\n");
	kill(mypid, SIGKILL);

	pthread_exit(0);
}

int main(int argc, char* argv[]) {

	char *fname;
	char buf[2048];

	pid_t pid;
	pid_t pid_child;
	//int status;

	pthread_t p_thread;
	int thr_id = 1;
	int tmp;

	unsigned char *BUF;
	int BUF_SIZE;
	int filedes;
	int total_sent, size, ret, i, checksum, filelen, total;

	Port = DOWNLOAD_PORT;
	BUF_SIZE = 2048;

	//port_num send sequence

	struct sockaddr_in nds_sin;
	struct sockaddr_in nds_cos;

	if ((ret = (clnt_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
			== -1) {
		fprintf(stderr, "Error at socket(): %d\n", data_socket);
		return -1;
	}

	nds_sin.sin_family = AF_INET;
	nds_sin.sin_addr.s_addr = htonl(INADDR_ANY);
	//nds_sin.sin_addr.s_addr = htonl(INADDR_ANY);
	nds_sin.sin_port = htons(Port);

	if (bind(clnt_socket, (struct sockaddr*) &nds_sin, sizeof(nds_sin)) == -1) {
		fprintf(stderr, "bind() error! - port %d\n", Port);
		return 1;
	}

	if (listen(clnt_socket, 1) == -1) {
		fprintf(stderr, "listen() error!\n");
		return 1;
	}

	while (1) {

		size = sizeof(nds_cos);
		data_socket = accept(clnt_socket, (struct sockaddr *) &nds_cos, &size);
		if (data_socket == -1) {
			//		printf("accept fail\n");
			disconnect_nds();
			fprintf(stderr, "accept() to DS Failed\n");
			exit(0);
		}

		if (Port > (DOWNLOAD_PORT + 995))
			Port = (DOWNLOAD_PORT + 1);
		Port = Port + 2;
		pid = fork();
		if (pid > 0) {
			pid_child = 0;
			while (pid_child == 0) {
				pid_child = waitpid(pid, NULL, 0);
			}
		} else if (pid < 0) {
			fprintf(stderr, "fork() Error!\n");
			disconnect_nds();
			exit(1);
		} else {
			pid_child = fork();
			if (pid_child < 0) {
				fprintf(stderr, "fork() Error!\n");
				disconnect_nds();
				exit(1);
			} else if (pid_child > 0) {	//Parent Process		
				//pid_child = waitpid(pid, &status, 0);
				pid_child = waitpid(pid, NULL, 0);
				if (pid_child)
					printf("Removed proc ID : %d\n", pid);

				close(data_socket);
				
				return ret;

			} else if (pid_child == 0) {
				//	printf("listen succes\n");			
				thr_id = pthread_create(&p_thread, NULL, t_function,
						(void*) tmp);
				sprintf(tmp_port, "%d", Port);
				send_data(tmp_port, MAX_SIZE);
				//port_num sent end

				//File Receive Sequence
				if (connect_pc() < 0) {
					goto leave0;
				}

				printf("connect success\n");
				BUF = (unsigned char*) malloc(sizeof(char) * BUF_SIZE + 1);

				printf("Magic Download Code Sent\n");

				memset(&FHeader, 0, sizeof(FHeader));
				if (read(clnt_socket, (struct header *) &FHeader,
						sizeof(FHeader)) != sizeof(FHeader)) {
					printf("Failed to send File Header\n");
					goto leave1;
				}

				filedes = open(tmp_port, O_WRONLY | O_CREAT | O_TRUNC, 0644);

				printf("Header receive\n");

				printf("Start Receiv Data\n");

				total = atoi(FHeader.filelength);

				memset(&buf, 0, sizeof(buf));
				fflush (stdout);
				while ((filelen = read(clnt_socket, buf, sizeof(buf))) > 0) {
					write(filedes, buf, filelen);
					total -= filelen;
					if (total <= 0)
						break;
					memset(&buf, 0, sizeof(buf));
				}
				printf("Transfer file: '%s' (%dB) Done!\n", FHeader.filename,
						atoi(FHeader.filelength));

				pthread_cancel(p_thread);
				leave1: free(BUF);
				//disconnect_nds();
				leave0: close(filedes);
				filesend();
				remove(tmp_port);
				goto end;
			}	//if(pid) end
		}
	}	//while() end
	end:

	return ret;

}

int filesend() {
	FILE *f2send;
	char *fname;
	unsigned char *BUF;
	int BUF_SIZE = 2048;

	int total_sent, size, ret, i, checksum;

	if ((f2send = fopen(tmp_port, "r+b")) == NULL) {

		return -1;
	}

	if (filelength > MAX_FILE_SIZE) {
		fprintf(stderr, "File size too big : MAX = %dBytes\n", MAX_FILE_SIZE);
		goto leave0;
	}

	ret = -1; // if return in error clause, ret = -1

	BUF = (unsigned char*) malloc(sizeof(char) * BUF_SIZE + 1);

	if (connect_nds() < 0) {
		goto leave0;
	}

	if (send_data(MAGIC_DOWNLOAD_STRING, MAGIC_LEN) != MAGIC_LEN) {
		printf("Failed to send Magic String\n");
		goto leave1;
	}

	printf("Magic Download Code Sent\n");

	if (send_data((unsigned char *) &FHeader, sizeof(FHeader))
			!= sizeof(FHeader)) {
		printf("Failed to send File Header\n");
		goto leave1;
	}

	printf("Header Sent\n");

	if (recv_data((unsigned char *) &FResp, sizeof(FResp)) != sizeof(FResp)) {
		printf("Failed to Recv Reponses\n");
		goto leave1;
	}

	if (strncmp(FResp.code, "000", 3)) {
		FResp.code[3] = 0;
		printf("Abort: %s: %s\n", FResp.code, FResp.string);
		goto leave1;
	}

	printf("Start Send Data\n");
	total_sent = checksum = 0;
	while (!feof(f2send)) {
		size = fread(BUF, 1, BUF_SIZE, f2send);
		if (!size)
			break;
		for (i = 0; i < size; i++)
			checksum += BUF[i];
		if (send_data(BUF, size) != size) {
			fprintf(stderr, "send error\n");
			goto leave1;
		}
		switch (Channel) {
		case CHANNEL_SERIAL:
		case CHANNEL_USB:
			sleep(0);
			break;
		}
		printf("\b\b\b\b\b\b\b\b\b\\b\b\b\b\b\b\b\b\b\b");
		printf("%dB Sent", total_sent);
		total_sent += size;

	}
	printf("\n");

	sprintf(BUF, "%d", checksum);
	//fprintf(stderr, "checksum: %s\n", BUF);
	if (send_data(BUF, MAX_FILE_LENGTH_LEN) != MAX_FILE_LENGTH_LEN) {
		printf("Failed to send Checksum\n");
		goto leave1;
	}
	printf("Checksum Sent\n");

	if (recv_data((unsigned char *) &FResp, sizeof(FResp)) != sizeof(FResp)) {
		printf("Failed to Recv Reponse\n");
		goto leave1;
	}

	if (strncmp(FResp.code, "000", 3)) {
		FResp.code[3] = 0;
		printf("Abort: %s: %s\n", FResp.code, FResp.string);
		goto leave1;
	}

	if (send_data(MAGIC_CLEANUP_STRING, MAGIC_LEN) != MAGIC_LEN) {
		printf("Failed to send Magic String\n");
		goto leave1;
	}

	printf("Magic Cleanup Code Sent\n");

	printf("Transfer file: '%s' (%dB) Done!\n", FHeader.filename,
			atoi(FHeader.filelength));

	ret = 0;

	leave1: free(BUF);
	close(data_socket);
	close(clnt_socket);
	leave0: fclose(f2send);
	return ret;
}
