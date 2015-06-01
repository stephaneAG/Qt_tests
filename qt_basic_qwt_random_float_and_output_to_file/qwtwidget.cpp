#include "qwtwidget.h"

Qwtwidget::Qwtwidget(QWidget *parent) : QWidget(parent) // constructor implementation
{
    // creation of tables of our data
    data_x = new QVector<double>;
    data_y = new QVector<double>;

    //init_port(); // init of the port
    init_fakereceiver(); // init the fake receiver
    init_plot(); // init of the graphic

    // creation of a layout to put the graphics inside
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setContentsMargins( 5, 5, 5, 5 ); // we set the margin of the layout
    layout->addWidget( plot ); //we add the plot to the layout
    

    // creation of the timer responsible for calling repeatedly the "fakeReceive" slot
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(fakeReceive()));
    timer->start(500); // set the timer to call "fakeReceive()" each half second ( 500 ms )
    // connection between the reception of a data and the function receive
    //connect(port,SIGNAL(readyRead()),this, SLOT(receive()));
}



Qwtwidget::~Qwtwidget() // destructor implementation
{
    //port->close(); //we close the port at the end of the program
  QTextStream out(stdout);
  out << "Program done." << endl;
  // MAYBE we could simply "file.close" here, if it's "THAT slow" (..)
}

/*
void Qwtwidget::init_port()
{
    QTextStream out(stdout); // creation of a stream belonging to the console ( we have to activate the console in the .pro file to display it )

    QString portname = "/dev/ttyACM0"; // Linux serial port where the Arduino is connected to
    port = new QextSerialPort(portname, QextSerialPort::EventDriven); // we create the port
    port->open(QIODevice::ReadWrite | QIODevice::Unbuffered); //we open the port
    if(!port->isOpen())
    {
        QMessageBox::warning(this, "port error", "Impossible to open the port: " + portname + "!");
    }

    //we set the port properties
    port->setBaudRate(BAUD9600);//modify the port settings on your own
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);

    out << "open" << endl << endl; // we write on the console
}
*/
void Qwtwidget::init_fakereceiver()
{
  // init the random seed
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
}

void Qwtwidget::init_plot()

{
    plot = new QwtPlot(this); //creation of the plot
    plot->setMinimumSize(500,250); //we set the minimum size of the plot
    plot->setTitle("Fake receiver"); //title of the graphe

    // axes names
    plot->setAxisTitle(QwtPlot::xBottom, "timestamp (half sec)" );
    plot->setAxisTitle(QwtPlot::yLeft, "confidence [0.0->1.0]" );

    // axis scale ( from xodingexodus test implms )
    //int plotCols = 3;
    //int plotRows = 2;
    //plot->setAxisScale(QwtPlot::xBottom, plotCols, 10.0, 100.0); // since we have fake numbers from 10->100
    //plot->setAxisScale(QwtPlot::yLeft, plotRows, 0.0, 255.0); // max 255 values on screen
    //plot->setAxisAutoScale(QwtPlot::xBottom, false); // disable auto-scaling the plot
    //setAxisScale(QwtPlot::xBottom, currTime - 15, currTIme + 15)
    //plot->setAxisScale(QwtPlot::xBottom, 0, 255); // working test
    plot->setAxisScale(QwtPlot::yLeft, 10, 100);
    plot->setAxisScale(QwtPlot::xBottom, 0, 120); // so if we get stuff each half second, the plot should be full in one minute

    // canvas properties
    plot->canvas()->setLineWidth( 1 );
    plot->canvas()->setFrameStyle( QFrame::Box | QFrame::Plain );
    plot->canvas()->setBorderRadius( 3 );

    // creation of the curve (you can add more curve to a graphe)
    curve = new QwtPlotCurve;
    curve->setPen(QPen(Qt::red));
    curve->attach(plot);

}

void Qwtwidget::save_defaultFile(int intToSaveToFile)
{
  QFile defaultFile("./qt_basic_qwt_random_float_and_output_to_file.log");
  //if( defaultFile.open(QFile::WriteOnly|QFile::Truncate) ) // overwrite existing file content
  if( defaultFile.open(QFile::Append|QFile::Text) ) // append to existing file content 
  {
    QTextStream dataOut(&defaultFile);
    dataOut << "'csv content';'scv int content';'" << intToSaveToFile <<  "'" << endl;
    defaultFile.close();
  }
}

/*
void Qwtwidget::receive()
{
    char data[255]; //creation of a char aray
    int bytesRead = port->read(data, 255); //load the port data
    data[bytesRead] = '\0'; //end the char aray

    //we convert the char into a integer
    int i=0;
    if (bytesRead==1)
    {
        i = data[0];
    }else return; // if the data size is different from 1 => exit the function

    QTextStream out(stdout);
    out << data << " (" << bytesRead << " bytes) understood :" << i<< endl; //writing the data read in the console

    addpoint(i); //we add a point to the graph
}
*/
void Qwtwidget::fakeReceive()
{
  // get a random number
  int i = qrand() % ( (100 + 1) - 10) + 10; // generate a random number between 10->100
  QTextStream out(stdout);
  out << "fakeReceived: " << i << endl; //writing the data read in the console
  
  save_defaultFile(i); // save the int received as a new line in the log file ( .csv in future ? )

  // as in this version we're not "handling stuff" like I used to do with Processing ( discard oldest value by "slidingDown" the array before redrawing it ), here we simply empty eat before redraw
  // Nb: as I just though about it: maybe we can actually make used of our "slideDown" fcn here ( -> once the graph is "full", slide it down before adding a point to it )
  // -- In that case, we may need ot modify the following "addPoint()" fcn (..)

  // for the moment, just clear the graph until we have it full
  out << "Current size of QVector:" << data_x->size() << endl;
  if( data_x->size() < 120 )
    addpoint(i); //we add a point to the graph
  else
    clearAndAddpoint(i); // clear and add point to the graph
}

void Qwtwidget::addpoint(int point)
{
    data_x->push_back(data_x->size());// add the point to the data
    data_y->push_back(point);

    curve->setSamples(*data_x,*data_y);// we set the data to the curve
    
    plot->replot(); // we redraw the graphe
}

void Qwtwidget::clearAndAddpoint(int point)
{
    data_x->clear();// clear the graphs
    data_y->clear();

    data_x->push_back(data_x->size());// add the point to the data
    data_y->push_back(point);

    curve->setSamples(*data_x,*data_y);// we set the data to the curve
		     
    plot->replot(); // we redraw the graphe
}
