#include "arduinowidget.h"

Arduinowidget::Arduinowidget(QWidget *parent) : QWidget(parent) // constructor implementation
{
    init_port(); //initiation of the port

    //creation and attribute of the slider
    slider = new QSlider(this);
    slider->resize(255,20);
    slider->setOrientation( Qt::Horizontal);
    slider->setRange(0,255);

    //creation and attribute of the lcd
    lcd = new QLCDNumber(this);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setFixedSize(180,100);

    //creation of a layout containing the slider and lcd
    main_layout = new QVBoxLayout(this);
    main_layout->addWidget(slider);
    main_layout->addWidget(lcd);

    //set the layout to the widget
    this->setLayout(main_layout);

    //connection between the slider event and the transmission function
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(transmitCmd(int)));

    //connection between the slider event and the lcd value
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
}



Arduinowidget::~Arduinowidget() // destructor implementation
{
    port->close(); //we close the port at the end of the program
}


void Arduinowidget::init_port()
{
    //port = new QextSerialPort("COM7"); //we create the port
    port = new QextSerialPort("/dev/ttyACM0"); // Linux tty where Arduino serial is connected
    port->open(QIODevice::ReadWrite | QIODevice::Unbuffered); //we open the port
    if(!port->isOpen())
    {
        QMessageBox::warning(this, "port error", "Impossible to open the port!");
    }

    //we set the port properties
    port->setBaudRate(BAUD9600);//modify the port settings on your own
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
}


void Arduinowidget::transmitCmd(int value)
{
  if(value < 0 || value >255) return; //if the value is not between 0 and 255

                                     //no transmission
  //char *buf; //creation of a buffer // TEF EDIT: commented out
  //*buf = value; // TEF EDIT: commented out

  //for messages longer than 1 character :
  /*
  char *buf[255]; //buffer size = 255char;
  sprintf(buf,"%c",value);
  */
  //port->write(buf); //send the buffer // TEF EDIT: commented out

  // TEF EDIT BELOW
  //port->write(QByteArray(1, (char)value)); //send the buffer ( untested )
  char buf = (char)value;
  port->write(&buf, 1); //send the buffer
  
  printf("writing: %d to buffer ...\n", value);
}
