/* plotmatrix.cpp */

/*
PlotMatrix::PlotMatrix(int rows, int columns, QWidget *parent = NULL);
  virtual ~PlotMatrix();

  int numRows() const;
  int numCols() const;
  QwtPlot *plot(int row, int column);
  const QwtPlot* plot(int row, int column) const;

  void setAxisScale(int axisId, int row, int col, double min, double max, double step = 0);
QVector<QwtPlot*> plotWidgets;
*/

#include <qlayout.h>
#include <qpen.h>
#include <qwt_plot.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>

#include "plotmatrix.h"

PlotMatrix::PlotMatrix(int numRows, int numColumns, QWidget *parent):
QFrame(parent)
{
  plotWidgets.resize(numRows * numColumns);
  QGridLayout *layout = new QGridLayout(this);
  for( int row = 0; row < numRows; row++ )
  {
    for( int col = 0; col < numColumns; col++ )
    {
      QwtPlot *plot = new QwtPlot(this);
      layout->addWidget(plot, row, col);
      plotWidgets[row * numColumns + col] = plot;
    }
  }
}

PlotMatrix::~PlotMatrix()
{
  foreach( QwtPlot *p, plotWidgets )
    delete p;
}

int PlotMatrix::numRows() const
{
  const QGridLayout *l = qobject_cast<const QGridLayout*>(layout());
  if( l )
    return l->rowCount();
  return 0;
}

int PlotMatrix::numColumns() const
{
  const QGridLayout *l = qobject_cast<const QGridLayout*>(layout());
  if( l )
    return l->columnCount();
  return 0;
}

QwtPlot* PlotMatrix::plot(int row, int column)
{
  const int index = row * numColumns() + column;
  if( index < plotWidgets.size() )
    return plotWidgets[index];
  return NULL;
}

const QwtPlot* PlotMatrix::plot(int row, int column) const
{
  const int index = row * numColumns() + column;
  if( index < plotWidgets.size() )
    return plotWidgets[index];
  return NULL;
}

void PlotMatrix::setAxisScale(int axisId, int row, int col, double min, double max, double step)
{
  QwtPlot *plt = plot(row, col);
  if( plt )
  {
    plt->setAxisScale(axisId, min, max, step);
    plt->updateAxes();
  }
}
