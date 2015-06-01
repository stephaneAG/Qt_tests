/* std_hello_wolrd - by StephaneAG 2013 */

/*
* most simple & basic stuff first
*/

#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QLabel hello("<center>Hello World once again !</center>");

	hello.setWindowTitle("std_hello_wolrd");
	hello.resize(400, 400);
	hello.show();

	
	return app.exec();
}
