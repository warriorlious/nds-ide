/**
 * @file hook_s5_full/pretask_instance11.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

/*Instance 11 of pretask*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_pretask_instance11(void)
{
	SCHEDULING_CHECK_STEP(11);
	
	tpl_send_it1();
	SuspendAllInterrupts();
	tpl_send_it1();
	ResumeAllInterrupts();
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq5_pretask_instance11(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_pretask_instance11",test_pretask_instance11)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence5",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}

/* End of file hook_s5_full/pretask_instance11.c */
