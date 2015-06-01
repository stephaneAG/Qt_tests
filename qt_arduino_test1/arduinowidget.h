#ifndef ARDUINOWIDGET_H
#define ARDUINOWIDGET_H

#include <QtGui/QWidget>
#include <QtGui>
#include <qextserialport.h>

class Arduinowidget : public QWidget
{
    Q_OBJECT

public:
    Arduinowidget(QWidget *parent = 0); // constructor
    ~Arduinowidget();  // destructor

    void init_port(); // port init fcn

public slots:

    void transmitCmd(int value); // sending fcn

private :

    QVBoxLayout *main_layout;
    QSlider *slider;
    QLCDNumber *lcd;
    QextSerialPort *port;
};



#endif // ARDUINOWIDGET_H
