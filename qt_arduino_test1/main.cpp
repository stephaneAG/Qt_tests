#include <QtGui/QApplication>
#include "arduinowidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Arduinowidget aw;
    aw.show();

    return a.exec();
}
