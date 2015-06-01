
/*
 *  Simple test program to test if it is possible & how simple it is ( if possible ) to connect a signal to a static fcn
 *  
 *  Note: only Qt > 5.0.2 ( otherwise, we need a 'singleton' to do so ( and surely other ways I don't know about yet ? ;p )
 *
 *
 *  by StephaneAG 2013
*/

#include <QtGui>

/* a dummy function */
void fileOpen()
{
  qDebug() << "ok";
}

/* Main App code */

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  QMenu menu;
  QAction* actionOpen = menu.addAction("test");

  QObject::connect(actionOpen, &QAction::triggered, fileOpen);

  menu.show();

  return app.exec();
}
