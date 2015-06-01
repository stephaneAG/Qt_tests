/* desktopwindow.c - a shared Xlib Desktop/Root Window hack library - by StephaneAG - 2013  */
/* this file is the implementation of all our functions */

//#include <stdio.h>
#include "desktopwindow.h"

Display *display; // the display
int screen; // the screen
GC gc; // the graphic context

/* current dirty hack*/
unsigned long int DesktopWindow; // the "Desktop" Window Id
unsigned long int ProgramWindow; // the Driver Program window Id
int thexpos; // the x position the program window will be at
int theypos; // the y position the program window will be at

/* simple test fcn to be called from external programs, for the most not using C ... */
void foo(void)
{
	puts("Hello I am a shared library");
}

/* fcn that implements a simplified version of the X11 XLib fcn called 'XReparentWIndow()' */
extern void reparentWindowTo(unsigned long int ProgWinId, unsigned long int DeskWinId, int xpos, int ypos){

	puts("Calling XReparentWIndow from the C shared library");

	//Display *display; // the display
	//int screen; // the screen
	//GC gc; // the graphic context

	/* current dirty hack*/
	unsigned long int DesktopWindow = DeskWinId; // the "Desktop" Window Id
	unsigned long int ProgramWindow = ProgWinId; // the Driver Program window Id
	int thexpos = xpos;
	int theypos = ypos;

	/* get the Xlib vars set up */
	display = XOpenDisplay(NULL );
        screen = DefaultScreen(display);
        gc = DefaultGC(display, screen);
        		
	XReparentWindow(display, ProgramWindow, DesktopWindow, thexpos, theypos); // WIP: trying 'dirty hack' without reparenting but instead directly adding stuff to the root window	
}
