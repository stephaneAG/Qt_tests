/* Qt Notepad ex - without sublassing QWidget - by StephaneAG 2013 */

/*
* most simple & basic stuff first
*/


/* Qt includes */
//#include <QApplication>
//#include <QLabel>
//#include <QTextEdit>
//#include <QWidget>
//#include <QWebView>
//#include <QtWebKit>
#include <QtGui>

/* custom QWidget subclasses */
#include "programwin.h"

/* std includes */
#include <stdio.h>


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
	
	//create a Notepad ( custom widget subclass )
	Programwin *programWin = new Programwin;
	programWin->show();
	
	// create a QWebView
	//QWebView *webview = new QWebView(); // needs a QWidget as parent ( ... )
     	//webview->load(QUrl("http://www.stephaneadamgarnier.com/qtdesktopwindow/index.html")); // load a Hello world html page
	//webview->load(QUrl("http://192.168.1.7:3000")); // one of the original purpose of the 'desktop window dirty hack' was brainApp ;p
	//webview->setGeometry(0, 0, 1280, 900);
     	//webview->show();
	
	return app.exec();
}
