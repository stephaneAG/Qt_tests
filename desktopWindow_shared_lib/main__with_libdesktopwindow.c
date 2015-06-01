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
	
	/* get the arguments 'as is' */
	char *progwinid = argv[1];
	char *deskwinid = argv[2];

	/* debug testing to get those hex out of char pointers correctly ... */
	//unsigned long int Fakeprogwinid = 0x2000079;
        //unsigned long int Fakedeskwinid = 0x2000004:

	/* print the hadcoded fake args */
        //fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Fake Arguments: %08lx as Program Window Id and %08lx as Desktop Window Id\n", Fakeprogwinid, Fakedeskwinid);

	
	/* prepare to get them as 'unsigned long int' */
	unsigned long int ulong_progwinid;
	unsigned long int ulong_deskwinid;
	
	
	/* print the arguments 'as is'*/
	fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received: %s as Program Window Id and %s as Desktop Window Id\n", progwinid, deskwinid);	
	//fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received: %lu as Program Window Id (ulong) and %lu as Desktop Window Id (ulong)\n", ulong_progwinid, ulong_deskwinid);
	printf("ld: %ld\n", strtol(argv[1], NULL, 16)); // print the hexadecimal received as argument in decimals ( works as 'xwininfo -int ...' )
	printf("lu: %lu\n", strtoul(argv[1], NULL, 16)); // same as above ?!
	//printf("%ld\n", strtol(argv[2], NULL, 16)); // print the hexadecimal received as argument in decimals ( works as 'xwininfo -int ...' )
        //printf("%lu\n", strtoul(argv[2], NULL, 16)); // same as above ?!
	printf("li: %li\n", strtoul(argv[1], NULL, 16)); // li
	printf("lx: %lx\n", strtoul(argv[1], NULL, 16)); // lx
	printf("lo: %lo\n", strtoul(argv[1], NULL, 16)); // lo
	printf("0x08lx: 0x%08lx\n", strtoul(argv[1], NULL, 16)); // lx
	printf("08lx: %08lx\n", strtoul(argv[1], NULL, 16)); // lx
	printf("8lx: %8lx\n", strtoul(argv[1], NULL, 16)); // lx	
	
	printf("#8lx: %#8lx\n", strtoul(argv[1], NULL, 16)); // lx : seems to be the correct formatting for my current purpose

	/* get the arguments into 'unsigned long int' and print them to stdout  */
	//sscanf(argv[1], "%ld", &ulong_progwinid);
	//sscanf(argv[2], "%ld", &ulong_deskwinid);
	//fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received: %lu as Program Window Id (ulong) and %lu as Desktop Window Id (ulong)\n", ulong_progwinid, ulong_deskwinid);
	
	sscanf(argv[1], "%08lx", &ulong_progwinid);
        sscanf(argv[2], "%08lx", &ulong_deskwinid);
        fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received: Ox%08lx as Program Window Id (ulong) and 0x%08lx as Desktop Window Id (ulong)\n", ulong_progwinid, ulong_deskwinid);

	sscanf(argv[1], "0x%08lx", &ulong_progwinid);
        sscanf(argv[2], "0x%08lx", &ulong_deskwinid);
	fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received: %08lx as Program Window Id (ulong) and %08lx as Desktop Window Id (ulong)\n", ulong_progwinid, ulong_deskwinid);	
	
	sscanf(argv[1], "%9lx", &ulong_progwinid);
        sscanf(argv[2], "%9lx", &ulong_deskwinid);
        fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received ( 9lx printed with format #8lx ): %#8lx as Program Window Id (ulong) and %#8lx as Desktop Window Id (ulong)\n", ulong_progwinid, ulong_deskwinid);
	fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received ( 9lx printed with format 9lx ): %9lx as Program Window Id (ulong) and %#8lx as Desktop Window Id (ulong)\n", ulong_progwinid, ulong_deskwinid);	
	
	sscanf(argv[1], "0x%lx", &ulong_progwinid);
        sscanf(argv[2], "0x%lx", &ulong_deskwinid);
        fprintf(stdout, "DESKTOPWINDOWHACK_HOTFIX: Received ( 0x lx printed with format #lx ): %#lx as Program Window Id (ulong) and %#lx as Desktop Window Id (ulong)\n", ulong_progwinid, ulong_deskwinid);


	puts("DESKTOPWINDOWHACK_HOTFIX: Shared Library test below for: libdesktopwindow");
	/* custom shared C libray: libdesktopwindow */
	foo(); // call the library test fcn
	
	/* 'fingercrossed' call of the embed 'XReparentWindow()' fcn inside libdesktopwindow */
	//reparentWindowTo(unsigned long int ProgWinId, unsigned long int DeskWinId, int xpos, int ypos);
	reparentWindowTo(ulong_progwinid, ulong_deskwinid, 0, 0);


	return 0;
}
