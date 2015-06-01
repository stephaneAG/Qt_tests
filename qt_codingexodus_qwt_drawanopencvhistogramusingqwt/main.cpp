/* qt_codingexodus_qwt_gettingstarted */

/* Qt includes */
#include <QApplication>
/* Qwt includes */
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
/* OpenCV includes */
#include <opencv2/core/core.hpp> /* located in /usr/include/opencv2/core/core.hpp*/
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv); // Qt-related
  
  /* OpenCV-related start */
  // read cli arguments
  if (argc < 2)
    return 1;
  // create input image
  cv::Mat img = cv::imread(argv[1]);
  // convert to grayscale
  if (img.data && img.channels() == 3)
    cv::cvtColor(img, img, CV_BGR2GRAY);
  else
    return 1;
  // histogram setup
  int histSize[1] = {256}; // number of bins
  float hranges[2] = {0.0, 255.0}; // min & max pixel values
  const float* ranges[1] = {hranges};
  int channels[1] = {0}; // only 1 channel used
  cv::MatND hist;
  // compute histogram
  cv::calcHist(&img, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
  double minVal, maxVal;
  cv::minMaxLoc(hist, &minVal, &maxVal); // locate max & min values
  /* OpenCV-related stop */

  /* Qwt-related start */
  // setup the Qwt plot
  QwtPlot plot;
  plot.setTitle("Plot Demo");
  plot.setCanvasBackground(Qt::black);
  plot.setAxisScale(QwtPlot::yLeft, minVal, maxVal); // scale the y axis
  plot.setAxisScale(QwtPlot::xBottom, 0, 255); // scale the x axis
  plot.insertLegend(new QwtLegend());

  // setup the grid
  //QwtPlotGrid *grid = new QwtPlotGrid();
  //grid->attach(&plot); // attach grid to plot

  // setup the curve
  QwtPlotCurve *curve = new QwtPlotCurve();
  curve->setTitle("count");
  curve->setPen(QPen(Qt::white, 2)); // set color & thickness for drawing the curve
  curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);

  // setup symbols
  //QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse, QBrush(Qt::yellow), QPen(Qt::red, 2), QSize(8, 8) );
  //curve->setSymbol(symbol);

  // setup the points
  QPolygonF points;
  //points << QPointF(0.0, 4.4) << QPointF(1.0, 3.0)
  //	 << QPointF(2.0, 4.5) << QPointF(3.0, 6.8) 
  //	 << QPointF(4.0, 7.9) << QPointF(5.0, 7.1);
  
  /* OpenCV-related start */
  // insert the points that should be plotted on the graph in a vector of QPointts or a QPolygonF
  for (int h = 0; h < histSize[0]; h++){
    float bin_value = hist.at<float>(h); // weird construction ( --> ".at(<float>(h))" ? )
    points << QPointF( (float)h, bin_value );
  } 
  /* OpenCV-related stop */

  // setup samples
  curve->setSamples(points);
  curve->attach(&plot); // attach curve to plot

  // setup how the plot will be shown
  plot.resize(600, 400);
  plot.show(); // show the plot ( as any other widget )

  /* Qwt-related end */

  return app.exec(); // Qt-related
}
