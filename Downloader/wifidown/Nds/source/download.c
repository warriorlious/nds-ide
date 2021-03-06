/************************************************************************
 *
 *                    Dall Shell for Nintendo DS
 *                   -----------------------------
 *           (C) Copyright 2009 by Minsuk Lee, Seoul, Korea
 *                      All Rights Reserved.
 *
 ************************************************************************/

/* FILE        : download.c
 *
 * Description : Dallshell Downloader
 *
 * Created - 2009-12-27 by Minsuk Lee
 * Revised - 2009-01-25 Enhance Error Processing by Minsuk Lee
 *         - 2009-XX-XX
 * Read    - 2009-01-22
 */

#include "dallshell.h"
#include "download.h"

#define KEY_A 0X0001
#define KEY_B 0X0002
#define KEY_X 0X0400
#define KEY_Y 0X0800
#define KEY_L 0X0200
#define KEY_R 0X0100
#define KEY_START 0X0008
#define KEY_SELECT 0X0004
#define KEY_UP 0X0040
#define KEY_DOWN 0X0080
#define KEY_LEFT 0X0020
#define KEY_RIGHT 0X0010

#define NDS_SWITCH() (keysCurrent() & 0xFFFF)

#define BUF_SIZE 4096
// -- End of Configurable Parameters

enum {
    DOWNLOAD_NCONNECTED,// NUMBER CONNECTED
    DOWNLOAD_NUMBER,    // DOWNLOAD
    DOWNLOAD_START,
    DOWNLOAD_CONNECTED,
    DOWNLOAD_MAGIC,
    DOWNLOAD_HEADER,
    DOWNLOAD_RECV,
    DOWNLOAD_FILE_DONE,
    DOWNLOAD_CHECKSUM,
    DOWNLOAD_DONE,
    DOWNLOAD_FAILED
};

// Progress bar sample : Filename:234/23982198

#define TEMP_FILENAME "TEMP.XXX"

static
void
disp_progress(int state, int value)
{
    struct links *channel;
    struct header *hp;
    //char *message;
    static int recv_count = 0;

    switch (state) {
	case DOWNLOAD_NCONNECTED :
            iprintf("Number Connected\n");
            break;
	case DOWNLOAD_NUMBER :
            channel = (struct links *)value;
	    //iprintf("%s Link Initialized\n", channel->read);
            iprintf("Number Code Received\n");
            break;
        case DOWNLOAD_START :
            channel = (struct links *)value;
            iprintf("%s Link Initialized\n", channel->name);
            iprintf("Download Sequence Started\n");
            recv_count = 0;
            break;
        case DOWNLOAD_CONNECTED :
            iprintf("Host Connected\n");
            break;
        case DOWNLOAD_MAGIC :
            iprintf("Magic Code Received\n");
            break;
        case DOWNLOAD_HEADER :
            hp = (struct header *)value;
            iprintf("Header Received\n%s (%sB)\n", hp->filename, hp->filelength);
            break;
        case DOWNLOAD_RECV :
            if (!recv_count)
                iprintf("Download (Byte) : ");
            else
                iprintf("\b\b\b\b\b\b\b\b\b");
            iprintf("%-9d", value);
            recv_count = 1;
            break;
        case DOWNLOAD_FILE_DONE :
            iprintf("\nDownload All File Data\n");
            break;
        case DOWNLOAD_CHECKSUM :
            iprintf("Download Checksum OK\n");
            break;
        case DOWNLOAD_DONE :
            iprintf("Download Done\n");
            break;
        case DOWNLOAD_FAILED :
            iprintf("\nDownload Failed\n");
            break;
        default :
            // Do nothing
            break;
    }
    // Disply It
}

static
void
response(struct links *channel, char *s)
{
    char BUF[RESPONSE_SIZE];
    sprintf(BUF, "000 NOERROR");
    channel->write(BUF, RESPONSE_SIZE);
}

#define RX_LOOP()   do {                        \
        while (size > 0) {                      \
            if (check_abort()) {                \
                ret = DSH_USER_ABORT;           \
                goto leave;                     \
            }                                   \
            ret = channel->read(p, size);       \
	    if (ret == DSH_WOULD_BLOCK)         \
                continue;                       \
            if (ret <= 0) {                     \
                ret = DSH_CONNECTION_CLOSED;    \
                goto leave;                     \
            }                                   \
            size -= ret;                        \
            p += ret;                           \
        }                                       \
    } while (0)

unsigned char XXX_BUF_[MAX_FILE_SIZE];
//unsigned char XXX_BUF_[1024];

int
download(struct links *channel, int *run, int *debug)
{

   unsigned char *p, *BUF = NULL;
//    unsigned char *mem_buf = _BIN_BUF;
    unsigned char *mem_buf = XXX_BUF_;
    struct header filehead;
    char filename[MAX_FILE_NAME_LEN + 1];
    int connected = 0;
    int response_sent = 0;
    int BinarySize;
    unsigned int checksum;
    int into_file = 0;          // Download into file too
    FILE* fp = NULL;
    int size, start, ret;
    int i;
    int Port_number;
    u8 sw;
    
    *run = *debug = 0;
    // Step 0: Prepare Channel and Wait Connection - Number
    
    if ((ret = channel->number()) < 0) {
        iprintf("download: Number connect() Error\n");
	
        goto leave;
    }
    
    disp_progress(DOWNLOAD_NCONNECTED, 0);

    // Step 1: Wait for Code Download String 
    
    if ((BUF = (unsigned char *)malloc(BUF_SIZE)) == NULL) {
        iprintf("download: malloc() Error\n");
        ret = DSH_NO_MEMORY;
        goto leave;
    }
    if(channel->read(BUF,sizeof(BUF)) <0){
    	 iprintf("download: Number Error\n");
	
        goto leave;
    }

    iprintf("Port : %d\n",atoi(BUF)+1);
    Port_number = atoi(BUF);
    disp_progress(DOWNLOAD_NUMBER, (int)channel);

    // Step 2: Disconnected
    
    if (connected)
        channel->disconnect();

    if (BUF)
        free(BUF);
    if (ret < 0)
        confirm_error("Download Error", 0);
    


    // Step 0: Prepare Channel and Wait Connection
    disp_progress(DOWNLOAD_START, (int)channel);
    if ((BUF = (unsigned char *)malloc(BUF_SIZE)) == NULL) {
        iprintf("download: malloc() Error\n");
        ret = DSH_NO_MEMORY;
        goto leave;
    }

    iprintf("plz Key-a click\n");
    sw = NDS_SWITCH();
  //i =0;
 
 while(1)
    {
	//iprintf("%d",i);
        //i++;
	if(sw & KEY_A)
		break;
	sw = NDS_SWITCH();
    }

    if ((ret = channel->connect(Port_number)) < 0) {
        iprintf("download: connect() Error\n");
	
        goto leave;
    }
    connected = 1;
    disp_progress(DOWNLOAD_CONNECTED, 0);

    // Step 1: Wait for Magic Download String

    size = MAGIC_LEN;
    start = 0;
    p = BUF;
    do {
        if (p != BUF) {
            size = 1;
            start++;
            if (start >= (BUF_SIZE - MAGIC_LEN - 1)) {
                iprintf("download: Magic String Receive Failed\n");
                ret = DSH_RX_ERROR;
                goto leave;
            }
        }
	
        RX_LOOP();
	
        *p = 0; // Make it ACSIZ
    } while (strcmp((char *)BUF + start, MAGIC_DOWNLOAD_STRING));
    disp_progress(DOWNLOAD_MAGIC, 0);

    // Step 2: Receive File Header

    size = HEADER_SIZE;
    p = (unsigned char *)&filehead;
    RX_LOOP();
    if (strlen(filehead.filename) > MAX_FILE_NAME_LEN) {
        iprintf("download: Invalid File Name\n");
        response(channel, "300 Invalid File Name");
        ret = DSH_INVALID_NAME;
        goto leave;
    }
    if (sscanf(filehead.filelength, "%d", &BinarySize) != 1) {
        iprintf("download: Invalid File Length format\n");
        response(channel, "400 Invalid File Length");
        goto len_e;
    }
    if (BinarySize < 0) {
        iprintf("download: Negative File Length");
        response(channel, "401 Invalid File Length < 0");
        goto len_e;
    }
    if (BinarySize == 0) {
        iprintf("download: File Length is Zero");
        response(channel, "402 Zero File Length");
        goto len_e;
    }
    if (BinarySize > MAX_FILE_SIZE) {
        iprintf("Invalid File Length : %dB\n", BinarySize);
        response(channel, "403 File Too Big");
len_e:  ret = DSH_INVALID_LENGTH;
        goto leave;
    }
    disp_progress(DOWNLOAD_HEADER, (int)&filehead);
    //iprintf("File Length = %dBytes\n", BinarySize);

    // Step 3: Open File

    if (Config.as_host_wish) {
        if (filehead.flash == 'F') {
            // if (file space < filelength)
            //    response(channel, "102 Not Enough File Space");
            into_file = 1;
        }
        if ((filehead.run == 'R') && (BinarySize < MAX_BINARY_SIZE))
            *run = 1;
        if (filehead.debug == 'D') {
            *debug = 1;
        }
    } else {
        if ((filehead.flash == 'F') || (filehead.run == 'R') || (filehead.debug == 'D')) {
            response(channel, "101 Host Options Ignored");
            response_sent = 1;
        }
        if (Config.flash)
            into_file = 1;
        if (Config.run && (BinarySize < MAX_BINARY_SIZE))
            *run = 1;
        if (Config.flash)
            *debug = 1;
    }
    if (into_file) {
        strcpy(filename, filehead.filename);
        if ((fp = fopen(filename, "wb")) == NULL) {
            iprintf("download: File Open Error\n");
            response(channel, "500 File Open Error");
            ret = DSH_FILE_OPEN;
            goto leave;
        }
    }
    if (!response_sent)
        response(channel, "100 Header OK");
    disp_progress(DOWNLOAD_RECV, 0);

    // Step 4: Receive File Data

    size = BinarySize;
    checksum = 0;
    while (size > 0) {
        if (check_abort()) {
            ret = DSH_USER_ABORT;
            goto leave;
        }
        ret = channel->read(BUF, (size < BUF_SIZE) ? size : BUF_SIZE);
        if (ret == DSH_WOULD_BLOCK)
            continue;
        if (ret <= 0) {
            ret = DSH_CONNECTION_CLOSED;
            goto leave;
        }
        //iprintf("<");
        memcpy(mem_buf, BUF, ret);
        //iprintf("a");
        size -= ret;
        mem_buf += ret;
        //iprintf("b");
        if (into_file) {
            if (ret != fwrite(BUF, sizeof(char), ret, fp)) {
                iprintf("download: File Write Error\n");
                response(channel, "501 File Write Error");
                ret = DSH_FILE_WRITE;
                goto leave;
            }
        }
        //iprintf("c");
        for (i = 0; i < ret; i++)
            checksum += BUF[i];
        //iprintf(">");
        disp_progress(DOWNLOAD_RECV, BinarySize - size);
    }
    disp_progress(DOWNLOAD_FILE_DONE, 0);

    // Step 5: Receive Checksum

    size = MAX_FILE_LENGTH_LEN;
    p = BUF;
    RX_LOOP();
    if (sscanf((char *)BUF, "%d", &ret) != 1)
        goto sum_e;
    if (ret != checksum) {
sum_e:  iprintf("download: Checksum Error\n");
        response(channel, "601 Checksum Error");
        ret = DSH_CHECKSUM;
        goto leave;
    }
    response(channel, "000 OK");
    disp_progress(DOWNLOAD_CHECKSUM, 0);

    // Step 6: Return

leave:
    if (ret == DSH_CONNECTION_CLOSED) {
        iprintf("download: Connection Closed\n");
    } else {
abort:  if (ret == DSH_USER_ABORT)
            response(channel, "800 Download Aborted by User");
        start = 0;
        do {
            if (check_abort()) {
                ret = DSH_USER_ABORT;
                goto abort;
            }
            ret = channel->read(BUF + start, 1);
            if (ret == DSH_WOULD_BLOCK)
                continue;
            if (ret <= 0) {
                ret = DSH_CONNECTION_CLOSED;
                iprintf("download: Connection Closed\n");
                break;
            }
            if (!strncmp((char *)BUF, MAGIC_CLEANUP_STRING, start + 1)) {
                if ((start + 1) != MAGIC_LEN)
                    start++;
                else {
                    ret = 0;
                    break;
                }
            } else
                memcpy(BUF, BUF + 1, MAGIC_LEN);
        } while (start < MAGIC_LEN);
    }
    if (connected)
        channel->disconnect();
    if (fp)
        fclose(fp);
    if (BUF)
        free(BUF);
    if (ret < 0)
        confirm_error("Download Error", 0);
    else
        disp_progress(DOWNLOAD_DONE, 0);
    return ret;//return 0;
}

