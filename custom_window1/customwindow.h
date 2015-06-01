#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QtGui/QWidget>

class CustomWindow : public QWidget {
	
	Q_OBJECT
	
	public:
		CustomWindow(QWidget *parent = 0);
		~CustomWindow();
	protected:
		void showEvent(QShowEvent *event);
		void paintEvent(QPaintEvent *event);
	
	private:
		void CenterOnScreen();
	
	
};

#endif
