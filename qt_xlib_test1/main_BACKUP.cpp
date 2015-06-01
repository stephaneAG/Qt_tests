/* std_hello_wolrd - by StephaneAG 2013 */

/*
* most simple & basic stuff first
*/


/* Qt includes */
#include <QApplication>
#include <QLabel>
#include <QWidget>

/* std includes */
#include <stdio.h>


/* X11 Xlib includes*/
#include <X11/Xlib.h>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	// creat the first widget
	QWidget widget1;
	widget1.setGeometry(44, 44, 666, 666);
	widget1.show();

	// creat the second widget
        QWidget widget2;
        widget2.setGeometry(144, 144, 666, 666);
        widget2.show();
	
	Display *display = XOpenDisplay(0); //0 parent for default values
	
	if (display != NULL){
		// create the X11 Window using Xlib
		Window w = XCreateWindow(display, DefaultRootWindow(display), 0, 0, 1200, 1100, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0);
		// reparent the widgets to the window created using Xlib
		XReparentWindow(display, widget1.winId(), w, 0, 0);
		XReparentWindow(display, widget2.winId(), w, 1, 10);
		// make the window visible on screen
		XMapWindow(display, w);

		XFlush(display);
	}
	else
		fprintf(stderr, "Error: Opening display");
	
	
	return app.exec();
}
