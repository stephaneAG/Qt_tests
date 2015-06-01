
/*
 *  Simple test program to test if it is possible & how simple it is ( if possible ) to connect a signal to a static fcn
 *  
 *  Note: only Qt > 5.0.2 ( otherwise, we need a 'singleton' to do so ( and surely other ways I don't know about yet ? ;p )
 *
 *
 *  by StephaneAG 2013
*/

#include <QtGui>
#include <iostream>

/* a dummy function */
void testFcn()
{
  qDebug() << ".. ok ..";
}

void beginFcn()
{
  qDebug() << "app begins ..";
}

void endFcn()
{
  std::cout << ".. app ends." << std::endl;
}

/* Main App code */

int main(int argc, char* argv[])
{
  beginFcn();
  QApplication app(argc, argv);

  testFcn();

  // force app to quit as we have nothing to do here ...
  //app.quit();
  app.exit();
  /* hacky-way ? */
  const int appRetVal = app.exec(); // hold the Qt's 'return app.exec()"
  endFcn(); // call our function that will do ( here, print ) stuff AFTER EVERYTHING HAS BEEN DONE WITH THE Qt STUFF (!)
  std::cout << "WTF ???!" << std::endl;
  return appRetVal;
}


/*
 *const int retval = app.exec();
   library_close();
     return retval;
 * */
