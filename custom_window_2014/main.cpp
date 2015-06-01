#include <QApplication>
#include <QDesktopWidget>
#include <QFrame>
#include <QtCore/QRect>

#include <QLabel>
// the line above imports stuff to load images

#include <QProcess>
// the line above imports some necessary stuff to run terminal commands from within Qt c++ code

//#include "customwindow.h"
// the line above imports the custom window declared in external .h/.cpp files

class FrameWindow{
	private:
		QDesktopWidget *desktop;
		QFrame frame_window;
		QRect frame_rect;
	public:
		FrameWindow(QApplication &app){
			desktop = app.desktop();
			int width = desktop->width();
			int height = desktop->height();
			
			frame_rect.setLeft( (width-400) / 2);
			frame_rect.setTop( (height-200) / 2);
			frame_rect.setRight( frame_rect.left() + 400);
			frame_rect.setBottom( frame_rect.top() + 200);
			
			frame_window.setGeometry( frame_rect );
			frame_window.setWindowTitle("Hello World !"); // set the title for that window
			
			// tests (...)
			frame_window.setWindowFlags(Qt::FramelessWindowHint); // chromeless window, centered (..)
			
			
			frame_window.setStyleSheet("background-color: white;"
									   "background-image: url(./128b128.png);"
									   "background-position: top left; "
                            		   "background-repeat: no-repeat;"
									   );
			
			//frame_window.setAttribute(Qt::WA_TranslucentBackground); // transparent borders (.. | on Ubuntu, no background)
			
			// add some stuff inside it
			QLabel hello("<center>Hi there !</center>");
			//QLabel *pLabel = new QLabel();
			//pLabel->setStyleSheet("QLabel { background-color: red; color: blue; }");
			//pLabel->setText("I am pLabel!");
			//pLabel->show();
			hello.show();
			
			frame_window.show();
		}
}; 

int main (int argc, char* argv[]){
	QApplication app(argc, argv);
	//CustomWindow custom_window(); // create an instance of our CustomWindow defined n the external files
	
	
	FrameWindow f_window(app); // create an instance of the window defined in the current file ( main.cpp )
	
		
	// test/debug/wip: execute a shell script -> works when in same folder as the .app
	//QProcess *proc = new QProcess();
	//proc->start("./play_paradox_music.sh");
	
	// test/debug/wip: add an image
	//QImage myImage;
	//myImage.load("128b128.png");
	//QLabel myLabel;
	//myLabel.setPixmap(QPixmap::fromImage(myImage));
	//myLabel.show();
	
	return app.exec();
}
