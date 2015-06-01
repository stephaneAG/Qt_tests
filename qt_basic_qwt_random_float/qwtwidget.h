/* qwtwidget.h - StephaneAG 2014 */

#ifndef QWTWIDGET_H
#define QWTWIDGET_H

/* Qt's 'basic' classes */
#include <QtGui/QWidget>
#include <QtGui>
#include <QVector>
#include <QTime> /* necessary for qsrand() */
#include <QTimer> /* ncecessary for Qt timers */

/* 'Qextserialport' class */
//#include <qextserialport.h>

/* 'Qwt' plot classes - included the C++ way */
//#include <qwt_plot>
//#include <qwt_plot_canvas>
//#include <qw_plot_curve>

/* 'Qwt' plot classes - qwt lib residing in the '3rd party libs directory' and using a symbolic link 'qwt' to the necessary lib & include directories */
//#include <qwt/qwt_plot>
//#include <qwt/qwt_plot_canvas>
//#include <qwt/qw_plot_curve>

/* include the C way */
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>



class Qwtwidget : public QWidget
{
    Q_OBJECT

public:
    Qwtwidget(QWidget *parent = 0); // constructor
    ~Qwtwidget();  // destructor

    //void init_port(); // port init fcn
    void addpoint(int point);//add a new point to the graph

public slots:

    //void transmitCmd(int value); // sending fcn
    //void receive(); //read data from the port
    void fakeReceive(); // get random data

private :

    //void init_port(); // port init fcn
    void init_fakereceiver();
    void init_plot();

    //QVBoxLayout *main_layout;
    //QSlider *slider;
    //QLCDNumber *lcd;
    //QextSerialPort *port;
    QwtPlot *plot;
    QwtPlotCurve *curve;
    QVector<double> *data_x, *data_y;
};



#endif // QWTWIDGET_H
