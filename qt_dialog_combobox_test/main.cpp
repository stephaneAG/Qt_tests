/* simple Qt test file  - using QDialog & QComboBox */

#include <QtGui/QApplication>

/* include our QDialog subclass class */
#include "dialogwindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  DialogWindow * dialwin = new DialogWindow();
  dialwin->show();

  return app.exec();
}
