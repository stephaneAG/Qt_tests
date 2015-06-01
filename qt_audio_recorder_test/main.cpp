#include "audiorecorder.h"

 #include <QtGui>

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     AudioRecorder recorder;
 #ifdef Q_OS_SYMBIAN
     recorder.showMaximized();
 #else
     recorder.show();
 #endif

     return app.exec();
 };
