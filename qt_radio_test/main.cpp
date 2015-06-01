#include "radio.h"

 #include <QtGui>

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     Radio radio;
 #ifdef Q_OS_SYMBIAN
     radio.showMaximized();
 #else
     radio.show();
 #endif

     return app.exec();
 };
