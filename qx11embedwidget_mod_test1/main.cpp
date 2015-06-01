/* QX11EmbedWIdget test 1 by StephaneAG - 2013 */

/*
*	The following test uses QX11EmbedWidget capabilities to use an external window to render, being given a Window Wid
*/

#include <QApplication>
#include <QX11EmbedWidget>

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     if (app.arguments().count() != 2) {
         qFatal("Error - expected window id as argument");
         return 1;
     }

     QString windowId(app.arguments()[1]);
     QX11EmbedWidget window;
     window.embedInto(windowId.toULong());
     window.show();

     return app.exec();
 }
