/* QVector test - StephaneAG 2014 */

/* Qt includes */
#include <QApplication>
//#include <QLabel>
//#include <QTextEdit>
//#include <QWidget>
//#include <QWebView>
//#include <QtWebKit>
//#include <QtGui>
#include <QVector>

/* std includes */
//#include <stdio.h>
#include <iostream>

// try to reimplement the functions I had in Processing/Java this time in C++

// fcn that re-indexes the values held in the QVector
void slideDownVector(QVector<float>& theVector)
{
  for( int i = 0; i < theVector.size() - 1; i++ )
    theVector[i] = theVector[i+1];
}

// fcn that add a value to the ones hled in the QVector
void addToVector(QVector<float>& theVector, float theValue)
{
  theVector[theVector.size()-1] = theValue;
}

// fcn that logs the content of the vector
void logVector(QVector<float>& theVector)
{
  for( int i = 0; i < theVector.size(); i++ )
    std::cout <<  "element number " << i+1 << " at index " << i  << " has for value: " << theVector.at(i) << std::endl;
}

// fcn that logs the current QVector's content & updates the QVector containing values with a new value after "sliding down" the QVector elements ( .. )
/*
void updateFuturegraphWithValue(QVector<float>& theVector, float theValue)
{
  logVector(theVector); // log the current content of the QVector
  slideDownVector(theVector); // "slide down" the content of the QVector
  addToVector(theVector, theValue); // update the cotnent of the QVector with the new value ( the one passed as parameter in the current function )
}
*/
void updateFuturegraphWithValue(QVector<float>* theVector, float theValue)
{
  std::cout << "Before:" << std::endl;
  logVector(*theVector); // log the current content of the QVector
  slideDownVector(*theVector); // "slide down" the content of the QVector
  addToVector(*theVector, theValue); // update the cotnent of the QVector with the new value ( the one passed as parameter in the current function )
  std::cout << ".. after:" << std::endl;
  logVector(*theVector);
}

// test fcn
void fcnAcceptingPtrToQVector(QVector<float>* theVectorPtr)
{
  std::cout << "I 've been invoked !" << std::endl;
  logVector(*theVectorPtr);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  // QVector test code //
  
  // create QVectors for testing purposes ( .. )
  QVector<float> arrayValues(10); // init a QVector of float type containing 10 elements
  QVector<float>* arrayValuesPtr = &arrayValues; // init a pointer to the above QVector
  QVector<float> arrayValuesOtherDefaults(10, 3.3); // same as above but set a value different than the default one

  // try to call the fcns declared above with them:
   // log them
   logVector(arrayValues);  
   logVector(arrayValuesOtherDefaults);
   // "slide them down" ( might not be visible unless we add stog to them later, as in the fcn WE WILL DEFINE ( * DON'T FORGET TO ! ;p )
   slideDownVector(arrayValues);
   slideDownVector(arrayValuesOtherDefaults);
   // add an arbitrary value to them the way we want (nb: Qt may have helper fcns to do this ->ask cousin ;p .. )
   addToVector(arrayValues, 4.4);
   addToVector(arrayValuesOtherDefaults, 4.4);
   // log them again
   logVector(arrayValues);
   logVector(arrayValuesOtherDefaults);

   std::cout << "\n Processing-like update: \n" << std::endl;
   // continue to do the same , but this time like I used to do in the Processing sketch "simpleOscillographClassInnerDrawColoredVersTestSketch" ( macbookpro )
   
   // test stuff ( .. )
   //fcnAcceptingPtrToQVector(arrayValuesPtr);
   //fcnAcceptingPtrToQVector(&arrayValuesOtherDefaults);

   // 1st pass
   updateFuturegraphWithValue(&arrayValues, 5.5);
   updateFuturegraphWithValue(&arrayValuesOtherDefaults, 5.5);
  
   // 2nd pass
   updateFuturegraphWithValue(&arrayValues, 7.7);
   updateFuturegraphWithValue(&arrayValuesOtherDefaults, 7.7);

  // end QVector test code //	

  std::cout << "Done !" << std::endl;
  exit (0);

  return app.exec();
}
