#include "customwindow.h"

#include <QDesktopWidget>

CustomWindow::CustomWindow(QWidget *parent) : QWidget(parent){
	resize(512, 512);
	setWindowTitle(tr("Tutorial Qt: CustomWindow") );
	setWindowFlags(Qt::FramelessWindowHint); // chromeless window
}

CustomWindow::~CustomWindow(){
	
}

void CustomWindow::showEvent(QShowEvent *event){
	Q_UNUSED(event);
	
	CenterOnScreen();
}

void CustomWindow::paintEvent(QPaintEvent *event){
	Q_UNUSED(event); // SAG Edit: added to prevent compilation errors 

	QPainter painter(this);
	QBrush background(QColor(23, 23, 34) );
	
	painter.setBrush(background);
	painter.setPen(Qt::NoPen); // no stroke
	painter.drawRect(0, 0, width(), height() );
}

void CustomWindow::CenterOnScreen(){
	QDesktopWidget screen;
	QRect screenGeom = screen.screenGeometry(this);
	
	int screenCenterX = screenGeom.center().x();
	int screenCenterY = screenGeom.center().y();
	
	move(screenCenterX - width() / 2, screenCenterY - height() / 2 );
}
