/* std_hello_wolrd - by StephaneAG 2013 */

/*
* most simple & basic stuff first
*/


/* std includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* X11 Xlib includes*/
#include <X11/Xlib.h>


/* X11 Xlib: global vars declaration */
Display *display; // the display
int screen; // the screen
Window win, root; // a window and the root window
GC gc; // the graphic context
unsigned long white_pixel, black_pixel;

/* current dirty hack*/
unsigned long int DesktopWinId;

/*
*	fcn associated with the "Expose" event
*/
void expose()
{
	XDrawString(display, win, gc, 10, 30, "Hello, world!", 14);
}


int main(int argc, char *argv[])
{
	//QApplication app(argc, argv);
	
	//QLabel hello("<center>Hello World once again !</center>");
	//hello.setWindowTitle("std_hello_world");
	//hello.resize(400, 400);
	//hello.show();

	/* X11 Xlib code from here */
	
	/* handle CLI parameters: actually, look for an externally-provided display parameter */
	char *dpyn = NULL;
	if ( argc == 3 ){
		if( strcmp(&argv[1][1], "display") == 0){
			dpyn = argv[2];
			fprintf(stdout, "CLI argument received: display is: %s .\n", argv[2] );
		}
		else {
			fprintf(stderr, "Usage: <script_name> [-display <display_name>] .\n");
			dpyn = getenv("DISPLAY");
			fprintf(stdout, "Now using default display.\n");
		}
	}
	else {
		dpyn = getenv("DISPLAY");
		fprintf(stdout, "Now using default display.\n");
	}	
	
	/* check if the display is actually ok */
	if ( ( display = XOpenDisplay(dpyn) ) == NULL ){
		fprintf(stderr, "Can't open the display ! \n");
		exit (1);
	}

	/* get the display*/
	//Display *display = XOpenDisplay(NULL); // by now ( by the way, provoques no errors, in addition to display nothing ;p )
	//display = XOpenDisplay( getenv("DISPLAY") ); // testing the environment variable ( echo $DISPLAY in shell )	

	/* get the global vars set up */
	screen = DefaultScreen(display);
	gc = DefaultGC(display, screen);
	root = RootWindow(display, screen);
	
	white_pixel = WhitePixel(display, screen);
	black_pixel = BlackPixel(display, screen);
	
	win = XCreateSimpleWindow(display, root, 0, 0, 100, 90, 2, black_pixel, white_pixel);
	
	/* attach events ( at least the one occuring at the creation of the window ) */
	XSelectInput(display, win, ExposureMask);
	
	/* add a title to the window */
	XStoreName(display, win, "xhelloworld");

	/* display the window on the screen */
	XMapWindow(display, win);

	/* lower its position in the staking order */
	XLowerWindow(display, win); // works: send the window in the lowest possible position, but still above desktop background (...)

	// == dirty hack == //
	DesktopWinId = 0x2000004; // hardcoded by now
	XReparentWindow(display, win, DesktopWinId, 0, 0);
	
	/* "active" part of the program: infinite loop of X events reading */
	for (;;){
		XEvent ev;
		//char c;
		
		XNextEvent(display, &ev);
		
		switch (ev.type){
			case Expose:
				expose();
				break;
			default:
				break;

		}

	}


	//XFlush(display);
	XCloseDisplay(display);
	/* end of X11 Xlib code */	

	
}
