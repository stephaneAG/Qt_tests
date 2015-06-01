/* plotmatrix.h */

#ifndef _PLOT_MATRIX_H_
#define _PLOT_MATRIX_H_

#include <qframe.h>
#include <qwt_plot.h> // also included in "main.cpp"

class PlotMatrix: public QFrame
{
  Q_OBJECT

  public:
	  PlotMatrix(int rows, int columns, QWidget *parent = NULL); // : QFrame(parent) ? ( .cpp )
	  virtual ~PlotMatrix();

	  int numRows() const;
	  int numColumns() const;
	  
	  QwtPlot *plot(int row, int column);
	  const QwtPlot* plot(int row, int column) const; //const; ?

	  void setAxisScale(int axisId, int row, int col, double min, double max, double step = 0);
  
  private:
	  QVector<QwtPlot*> plotWidgets;

};

#endif // _PLOT_MATRIX_H_
