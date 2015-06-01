/* notepad.h - simple example of Notepad using a class - by StephaneAG - 2013  */
#include <QtGui>
#include <QWidget>

class Notepad : public QWidget
{
	Q_OBJECT

	public:
		Notepad();
	private slots:
		void quit();
	private:
		QTextEdit *textEdit;
		QPushButton *quitButton;

};
