/* programwin.h - simple program window using a class - by StephaneAG - 2013  */
#include <QtGui>
#include <QWidget>

//class Programwin : public QWidget
class Programwin : public QMainWindow
{
	Q_OBJECT

	public:
		Programwin();

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
