#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QtGui>
#include <QVector>

#include <qextserialport.h>

#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0); //creation function
    ~Widget();//destructor

    void addpoint(int point);//add a new point to the graphe


public slots:
    void receive(); //read data from the port


private :
    void init_port();
    void init_plot();

    QextSerialPort *port;
    QwtPlot *plot;
    QwtPlotCurve *curve;
    QVector<double> *data_x, *data_y;

};

#endif // WIDGET_H
