#include <QtGui>

 #include "audiooutput.h"

 int main(int argv, char **args)
 {
     QApplication app(argv, args);
     app.setApplicationName("Audio Output Test");

     AudioTest audio;
 #if defined(Q_OS_SYMBIAN)
     audio.showMaximized();
 #else
     audio.show();
 #endif

     return app.exec();
 }
