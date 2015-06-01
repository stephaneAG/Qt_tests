/* notepad.h - simple example of Notepad using a class - by StephaneAG - 2013  */
#include <QtGui>
#include <QWidget>

//class Notepad : public QWidget
class Notepad : public QMainWindow
{
	Q_OBJECT

	public:
		Notepad();

	private slots:
		void open();
		void save();
		void quit();
	private:
		QTextEdit *textEdit;
		//QPushButton *quitButton;
		QAction *openAction;
		QAction *saveAction;
		QAction *exitAction;

		QMenu *fileMenu;
};
