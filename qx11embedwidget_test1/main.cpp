/* QX11EmbedWIdget test 1 by StephaneAG - 2013 */

/*
*	The following test uses QX11EmbedWidget capabilities to use an external window to render, being given a Window Wid
*/

#include <QApplication>
#include <QX11EmbedWidget>
#include <QDebug>

/* == dirty hack v1 == */
//ulong DesktopWindId;

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     ulong DesktopWinId = 0x200004; // hardcoded by now (...)

     if (app.arguments().count() != 2) {
         qFatal("Error - expected window id as argument");
         return 1;
     }

     QString windowId(app.arguments()[1]);
     qDebug() << "QX11Embed - dirty hack: Received WinId argument:" << windowId;

     QX11EmbedWidget window; // Note: the Qt example was missing the 'QX11' in 'QX11EmbedWidget' -> quite 'not practical', for an example (...)
     //window.embedInto(windowId.toULong()); // original code from Qt example
     window.embedInto(DesktopWinId.toUlong()); // hardcoded for nox (...)
     window.show();

     return app.exec();
 }
