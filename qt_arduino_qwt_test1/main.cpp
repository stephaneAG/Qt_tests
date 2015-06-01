#include <QtGui/QApplication>
#include "arduinoqwtwidget.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Arduinoqwtwidget aqw;
    aqw.show();

    return a.exec();
}
