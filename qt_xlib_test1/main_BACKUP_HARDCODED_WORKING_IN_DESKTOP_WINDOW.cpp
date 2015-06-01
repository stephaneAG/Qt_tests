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

/* == dirty hack for Xlib/Qt v1.5 == */
unsigned long int DesktopWinId;
//QString qDesktopWinId;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// == modding for external window support == //
	//QString externalWinId;
	//if (app.arguments().count() == 2) {
        // 	fprintf(stdout, "Using the provided Wid to render on external window.\n");
	//	DesktopWinId = app.arguments()[1] ;
	//	fprintf(stdout, "Using provided Window.\n");
        //}
	DesktopWinId = 0x2000004; // hardcoded by now (...)
	
	// creat the first widget
	QWidget widget1;
	widget1.setGeometry(44, 44, 666, 666);
	widget1.show();

	// creat the second widget
        QWidget widget2;
        widget2.setGeometry(144, 144, 666, 666);
        widget2.show();
	
	Display *display = XOpenDisplay(0); //0 parent for default values
	
	if (display != NULL ){
		// create the X11 Window using Xlib
		//Window w = XCreateWindow(display, DefaultRootWindow(display), 0, 0, 1200, 1100, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0); // 'normal way' ( see below )
		Window w = XCreateWindow(display, DesktopWinId, 0, 0, 1200, 1100, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0); // 'dirty hack' v1.5 way
		// Above not necessary cause now reparenting directly the Qt Widgets to the root/desktop window
		// the above seems not to work ( or maybe 've done something wrong ? ) , so now trying with 'XReparentWindow' before moving on to testing the hack with 'QX11EmbedWIdget' (...)
		
		// reparent the widgets to the window created using Xlib
		//XReparentWindow(display, widget1.winId(), w, 0, 0);
                //XReparentWindow(display, widget2.winId(), w, 1, 10);		

		// == dirty ( little ) hack : reparenting Qt Widgets to Xlib Window == //
		XReparentWindow(display, widget1.winId(), w, 0, 0);
		XReparentWindow(display, widget2.winId(), w, 1, 10);
		// make the window visible on screen
		//XMapWindow(display, windowId);
		//XMapWindow(display, externalWinId);
		XMapWindow(display, w);// 'dirty hack' v1.5: try a call to 'XMapWindow()' on the Desktop window [ wich should actually be visible ]

		XFlush(display);
	}
	else{
		fprintf(stderr, "Error: Opening display or no Wid passed to render on an external window: creating and rendering in a new window.");
		//Window w = XCreateWindow(display, DefaultRootWindow(display), 0, 0, 1200, 1100, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0);
		//XReparentWindow(display, widget1.winId(), w, 0, 0);
                //XReparentWindow(display, widget2.winId(), w, 1, 10);
	}
	
	return app.exec();
}
