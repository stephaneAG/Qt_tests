/* qt_codingexodus_qwt_gettingstarted */

/* Qt includes */
#include <QApplication>
/* Qwt includes */
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv); // Qt-related
  
  /* Qwt-related start */
  // setup the Qwt plot
  QwtPlot plot;
  plot.setTitle("Plot Demo");
  plot.setCanvasBackground(Qt::white);
  plot.setAxisScale(QwtPlot::yLeft, 0.0, 10.0);
  plot.insertLegend(new QwtLegend());

  // setup the grid
  QwtPlotGrid *grid = new QwtPlotGrid();
  grid->attach(&plot); // attach grid to plot

  // setup the curve
  QwtPlotCurve *curve = new QwtPlotCurve();
  curve->setTitle("Pixel Count");
  curve->setPen(QPen(Qt::blue, 4));
  curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);

  // setup symbols
  QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse, QBrush(Qt::yellow), QPen(Qt::red, 2), QSize(8, 8) );
  curve->setSymbol(symbol);

  // setup the points
  QPolygonF points;
  points << QPointF(0.0, 4.4) << QPointF(1.0, 3.0)
	 << QPointF(2.0, 4.5) << QPointF(3.0, 6.8) 
	 << QPointF(4.0, 7.9) << QPointF(5.0, 7.1);

  // setup samples
  curve->setSamples(points);
  curve->attach(&plot); // attach curve to plot

  // setup how the plot will be shown
  plot.resize(600, 400);
  plot.show(); // show the plot ( as any other widget )

  /* Qwt-related end */

  return app.exec(); // Qt-related
}
