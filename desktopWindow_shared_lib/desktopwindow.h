/* desktopwindow.h - a shared Xlib Desktop/Root Window hack library - by StephaneAG - 2013  */
/* this file defines the interface to our library */

/* std includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* X11 Xlib includes*/
#include <X11/Xlib.h>


#ifndef desktopwindow_h
#define desktopwindow_h

/* X11 Xlib: global vars declaration */
//Display *display; // the display
//int screen; // the screen
//GC gc; // the graphic context

/* current dirty hack*/
//unsigned long int DesktopWindow; // the "Desktop" Window Id
//unsigned long int ProgramWindow; // the Driver Program window Id
//int thexpos; // the x position the program window will be at
//int theypos; // the y position the program window will be at

extern void foo(void);

extern void reparentWindowTo(unsigned long int ProgWinId, unsigned long int DeskWinId, int xpos, int ypos);



#endif // desktopwindow_h
