#include <QtGui/QApplication>
#include "widget.h"
#include <QtGui>

//here you have nothing to add

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
