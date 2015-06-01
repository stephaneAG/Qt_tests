#include "arduinoqwtwidget.h"

Arduinoqwtwidget::Arduinoqwtwidget(QWidget *parent) : QWidget(parent) // constructor implementation
{
    // creation of tables of our data
    data_x = new QVector<double>;
    data_y = new QVector<double>;

    init_port(); // init of the port
    init_plot(); // init of the graphic

    // creation of a layout to put the graphics inside
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setContentsMargins( 5, 5, 5, 5 ); // we set the margin of the layout
    layout->addWidget( plot ); //we add the plot to the layout

    // connection between the reception of a data and the function receive
    connect(port,SIGNAL(readyRead()),this, SLOT(receive()));
}



Arduinoqwtwidget::~Arduinoqwtwidget() // destructor implementation
{
    port->close(); //we close the port at the end of the program
}


void Arduinoqwtwidget::init_port()
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


void Arduinoqwtwidget::init_plot()

{
    plot = new QwtPlot(this); //creation of the plot
    plot->setMinimumSize(500,250); //we set the minimum size of the plot
    plot->setTitle("T = f(t)"); //title of the graphe

    // axes names
    plot->setAxisTitle(QwtPlot::xBottom, "t (s)" );
    plot->setAxisTitle(QwtPlot::yLeft, "T (°C)" );

    // canvas properties
    plot->canvas()->setLineWidth( 1 );
    plot->canvas()->setFrameStyle( QFrame::Box | QFrame::Plain );
    plot->canvas()->setBorderRadius( 3 );

    // creation of the curve (you can add more curve to a graphe)
    curve = new QwtPlotCurve;
    curve->setPen(QPen(Qt::red));
    curve->attach(plot);

}


void Arduinoqwtwidget::receive()
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

    addpoint(i); //we add a point to the graphe
}


void Arduinoqwtwidget::addpoint(int point)
{
    data_x->push_back(data_x->size());// add the point to the data
    data_y->push_back(point);

    curve->setSamples(*data_x,*data_y);// we set the data to the curve
    
    plot->replot(); // we redraw the graphe
}
