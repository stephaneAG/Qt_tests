/* Qt Qwt basic random float test - StephaneAG 2014 */

/* Qt includes */
#include <QtGui/QApplication>
#include <QtGui>
/* custom classes includes */
#include "qwtwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Qt-related
    
    Qwtwidget qw; // instanciate our custom widget class
    qw.show(); // show it

    return a.exec(); // Qt-related
}
