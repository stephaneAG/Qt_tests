/* main.c - this program is a 'hotfix' that uses the shared Xlib Desktop/Root Window hack library - by StephaneAG - 2013  */

/* 	this short program is a 'hotfix' in the sense that it should be executable 
*	from a shell command, a bash script, or even from Java/Python programs
*	when ran as a shell command.
*	
*	It should not throw any dependencies errors as it has already been linked against
*	the right libraries during compiling.
*
*	Internally, it uses the 'desktopwindow' C shared library,
*	wich may be a little bit 'overkill' since it doesn't ( and won't )
*	contain some much stuff after all (...)
*
*	Still, for a wip impl, it may indeed help in the resolution of the original 'problem'
*/


/* std libs */
#include <stdio.h>
#include <stdlib.h>

/* custom shared C libray: libdesktopwindow */
#include "desktopwindow.h" // we include our library

//int main(void)
int main(int argc, char **argv)
{
	/* check the number of arguments */
	if (argc < 3)
	{
		fprintf(stderr, "DESKTOPWINDOWHACK_HOTFIX: Error: invalid number of argmuments\n");
		fprintf(stderr,"Usage: ./desktopwindowhack_hotfix <program_window_id> <desktop_window_id>\n");
		exit (1);
	}
	
	/* parse the arguments */
	char *progwinid = argv[1];
	char *deskwinid = argv[2];
	fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received: %s as Program Window Id and %s as Desktop Window Id\n");	
	

	puts("DESKTOPWINDOWHACK_HOTFIX: Shared Library test below for: libdesktopwindow");
	/* custom shared C libray: libdesktopwindow */
	foo(); // call the library test fcn
	
	return 0;
}
