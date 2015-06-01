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

#include "plotmatrix.h"

/* fcn(s) */
// Nb: has changed a little since the last tut'
void getPoints( cv::MatND& hist, int* histSize, QPolygonF& points )
{
  points.clear();
  for( int h =0; h < histSize[0]; h++ )
  {
    float bin_value = hist.at<float>(h);
    points << QPointF((float)h, bin_value);
  }
}

/* class(es) */
class MainWindow: public PlotMatrix
{
  public:
	MainWindow():PlotMatrix(2, 7) // ORIGINAL TUT: 2,3 || 3 HORIZ.: 1,3 || 3 VERT.: 3,1
        {
          for( int row = 0; row < numRows(); row++ )
          {
            for( int col = 0; col < numColumns(); col++ )
            {
              // set default scale if any
      	      setAxisScale(QwtPlot::yLeft, row, col, 0, 100);
	      setAxisScale(QwtPlot::xBottom, row, col, 0, 255);
	
	      QwtPlot *plt = plot(row, col);
	      plt->setCanvasBackground(QColor(Qt::darkGray));

	      // allow the Axis to scale automatically // HEEEEERE!!!!!! ;p
	      plt->setAxisAutoScale(QwtPlot::yLeft, true);

	      // show plot grid lines just for aesthetics
	      QwtPlotGrid *grid = new QwtPlotGrid();
	      grid->enableXMin(true);
	      //grid->QwtPlotGrid::setMajorPen(Qt::white, 0.0, Qt::DashLine); // DIGG THE TUT'S ERROR
	      //grid->QwtPlotGrid::setMinorPen(Qt::gray, 0.0, Qt::DotLine); // SAME AS ABOVE
	      //grid->setPen(QPen(Qt::gray, 0, Qt::DashLine)); // semms to pass ( ..)
	      grid->setPen(QPen(Qt::gray, 0));
	      grid->attach(plt);
            }
          }
        }
};


// Nb: new version is just below, uncommented
/*
class Curve: public QwtPlotCurve
{
  public:
	  Curve(const QString &title):
           QwtPlotCurve(title)
	   {
	     setRenderHint(QwtPlotItem::RenderAntialiased); 
	   }
	  void setColour(const QColor &color, int penSize)
	  {
	    QColor c = color;
	    c.setAlpha(150);
	    setPen(QPen(c, penSize)); // ORIGINAL TUT'S CODE: " QwtPlotCurve::setPen(c, penSize); "
	    //setBrush(c); // TO COMMENT OUT TO HAVE "SIMPLE LINES" INSTEAD OF "FILLED SHAPES"
	  }
};
*/

class Curve: public QwtPlotCurve
{
  public:
	  Curve( const QString &title, const QColor &colour, int penSize, QPolygonF &points ): QwtPlotCurve(title)
	  {
  	    QColor c = colour;
            c.setAlpha(150); // handle colour transparency
            setPen(QPen(c, penSize));
            //setBrush(c); // line to comment out to get unfilled stuff if I recall correctly
            setSamples(points);
            setRenderHint(QwtPlotItem::RenderAntialiased);
          }
};


int main(int argc, char *argv[])
{
  QApplication app(argc, argv); // Qt-related
  
  /* OpenCV-related start */
  // read cli arguments
  if (argc < 2)
    return 1;
  // create / read input image
  cv::Mat img = cv::imread(argv[1]);
  // convert to grayscale / NB: KEPT FROM THE 2 PREVIOUS TUT'S CAUSE A DIFFERENT IN THE CURRENT ONE & THE NEXT ( multichannel histogram / matrix of histograms )
  /*
  if (img.data && img.channels() == 3)
    cv::cvtColor(img, img, CV_BGR2GRAY);
  else
    return 1;
  */
  if (img.data && img.channels() != 3)
    return 1;
  
  // As we're now using the "MainWindow" class declared above in the current file, we create an instance of it here
  MainWindow mainWindow;
  mainWindow.resize(600, 400);

  // histogram setup / NB: A LITTLE DIFFERENT THAN THE ONE IN PREVIOUS TUT'S ( ~aka "size of array-like stuff is not set manually ( .. )" )
  int histSize[] = {256}; // number of bins
  float hranges[] = {0.0, 255.0}; // min & max pixel values
  const float* ranges[] = {hranges};
  int channels[] = {0}; // only 1 channel used
  // NEW CODE BELOW
  std::vector<cv::Mat> rgbChannels(3);
  cv::split(img, rgbChannels);
  cv::MatND hist;
  // compute histogram
  //cv::calcHist(&img, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
  //double minVal, maxVal;
  //cv::minMaxLoc(hist, &minVal, &maxVal); // locate max & min values
  
  /* OpenCV-related stop */

  /* Qwt-related start */
  /*
  // setup the Qwt plot
  QwtPlot plot;
  plot.setTitle("Plot Demo");
  plot.setCanvasBackground(Qt::white);
  //plot.setAxisScale(QwtPlot::yLeft, minVal, maxVal); // scale the y axis
  plot.setAxisScale(QwtPlot::xBottom, 0, 255); // scale the x axis
  plot.insertLegend(new QwtLegend());
  */
  // setup the grid
  //QwtPlotGrid *grid = new QwtPlotGrid();
  //grid->attach(&plot); // attach grid to plot

  /*
  // setup the curve / NB/ NOW DONE USING THE 'Curve' class
  QwtPlotCurve *curve = new QwtPlotCurve();
  curve->setTitle("count");
  curve->setPen(QPen(Qt::white, 2)); // set color & thickness for drawing the curve
  curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
  */

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
  /*
  for (int h = 0; h < histSize[0]; h++){
    float bin_value = hist.at<float>(h); // weird construction ( --> ".at(<float>(h))" ? )
    points << QPointF( (float)h, bin_value );
  }
  */

  // NEW CODE BELOW / NB: NOW IT'S A MIX OF OPENCV & QWT CODE ( .. )
  // Red channel
  cv::calcHist(&rgbChannels[2], 1, channels, cv::Mat(), hist, 1, histSize, ranges);
  //Curve *curve = new Curve("Red Channel"); // Nb: here we first create the "curve"
  //curve->setColour(Qt::red, 2); // set the color & the thickness for the curve to be drawn
  getPoints(hist, histSize, points); // insert the points that should be plotted on the graph in a vector of QPointts or a QPolygonF
  Curve *curve = new Curve("Red Channel", Qt::red, 2, points); // Nb: here we first create the "curve"
  //curve->setZ(curve->z() -1);
  //curve->setSamples(points); // pass the points to be drawn on the curve
  //curve->attach(&plot); // attach the curve to the plot
  curve->attach(mainWindow.plot(0, 0)); // attach the curve to the plot
  // Green channel
  cv::calcHist(&rgbChannels[1], 1, channels, cv::Mat(), hist, 1, histSize, ranges);
  //curve = new Curve("Green Channel"); // Nb: here we reuse the previous "curve" object ( .. )
  //curve->setColour(Qt::green, 2);
  //points.clear(); // clear the previous content ( -> items in ) of the "points" object ( QPolygonF )
  getPoints(hist, histSize, points);
  curve = new Curve("Green Channel", Qt::green, 2, points); // Nb: here we reuse the previous "curve" object ( .. )
  //curve->setZ(curve->z() -2);
  //curve->setSamples(points);
  //curve->attach(&plot);
  curve->attach(mainWindow.plot(0, 1));
  // Blue channel
  cv::calcHist(&rgbChannels[0], 1, channels, cv::Mat(), hist, 1, histSize, ranges);
  //curve = new Curve("Blue Channel");
  //curve->setColour(Qt::blue, 2);
  //points.clear();
  getPoints(hist, histSize, points);
  curve = new Curve("Blue Channel", Qt::blue, 2, points);
  //curve->setZ(curve->z() -3);
  //curve->setSamples(points);
  //curve->attach(&plot);
  curve->attach(mainWindow.plot(0, 2));

  /* OpenCV-related stop */

  // setup samples
  //curve->setSamples(points);
  //curve->attach(&plot); // attach curve to plot

  /*
  // setup how the plot will be shown
  plot.resize(600, 400);
  plot.show(); // show the plot ( as any other widget )
  */
  /* Qwt-related end */
  mainWindow.show();

  return app.exec(); // Qt-related
}
