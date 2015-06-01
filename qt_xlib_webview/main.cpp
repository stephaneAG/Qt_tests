/* std_hello_wolrd - by StephaneAG 2013 */

/*
* most simple & basic stuff first
*/


/* Qt includes */
#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QWidget>
#include <QWebView>
#include <QtWebKit>

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
	//DesktopWinId = 0x2000004; // hardcoded by now (...)
	DesktopWinId = 0x1e00004; // stil hardcoded here, but see the "Xlib only" directory for a try to parse it as any other argument ( .. )
	// Edited by Tef on 12/01/2014 as the Desktop WinId seems to have changed

	// creat the first widget
	//QWidget widget1;
	//widget1.setGeometry(44, 44, 666, 666);
	//widget1.show();

	// creat the second widget
        //QWidget widget2;
        //widget2.setGeometry(144, 144, 666, 666);
        //widget2.show();
	
	// create a text edit
	//QTextEdit textEdit;
	//textEdit.show();
	
	// create a QWebView
	QWebView *webview = new QWebView(); // needs a QWidget as parent ( ... )
     	//webview->load(QUrl("http://www.stephaneadamgarnier.com/qtdesktopwindow/index.html")); // load a Hello world html page
	webview->load(QUrl("http://192.168.1.7:3000")); // one of the original purpose of the 'desktop window dirty hack' was brainApp ;p
	webview->setGeometry(0, 0, 1280, 900);
     	webview->show();
	

	Display *display = XOpenDisplay(0); //0 parent for default values
	
	if (display != NULL ){
		// create the X11 Window using Xlib
		//Window w = XCreateWindow(display, DefaultRootWindow(display), 0, 0, 1200, 1100, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0); // 'normal way' ( see below )
		//Window w = XCreateWindow(display, DesktopWinId, 0, 0, 1200, 1100, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0); // 'dirty hack' v1.5 way
		// Above not necessary cause now reparenting directly the Qt Widgets to the root/desktop window
		// the above seems not to work ( or maybe 've done something wrong ? ) , so now trying with 'XReparentWindow' before moving on to testing the hack with 'QX11EmbedWIdget' (...)
		
		// reparent the widgets to the window created using Xlib
		//XReparentWindow(display, widget1.winId(), w, 0, 0);
                //XReparentWindow(display, widget2.winId(), w, 1, 10);		

		// == dirty  hack v2 : reparenting Qt Widgets DIRECTLY to Root/Desktop Window == //
		//XReparentWindow(display, widget1.winId(), DesktopWinId, 0, 0); 
		//XReparentWindow(display, widget2.winId(), DesktopWinId, 1, 10);
		//XReparentWindow(display, textEdit.winId(), DesktopWinId, 30, 100);
		XReparentWindow(display, webview->winId(), DesktopWinId, 320, 180);
		//XReparentWindow(display, webview, DesktopWinId, 3, 20);
		// make the window visible on screen
		//XMapWindow(display, windowId);
		//XMapWindow(display, externalWinId);
		//XMapWindow(display, w);// 'dirty hack' v1.5: try a call to 'XMapWindow()' on the Desktop window [ wich should actually be visible, but seems needed (...) ]
		// the above should not be needed as the Root/Desktop window is arleady visible on the desktop ( and as we're reparenting, it wouldn't be 'that logical' ? ;D ) 		

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
