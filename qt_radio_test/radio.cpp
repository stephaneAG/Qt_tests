
 #include "radio.h"

 #include <QtGui>

 Radio::Radio()
 {
     radio = new QRadioTuner;
     connect(radio,SIGNAL(frequencyChanged(int)),this,SLOT(freqChanged(int)));
     connect(radio,SIGNAL(signalStrengthChanged(int)),this,SLOT(signalChanged(int)));
     connect(radio, SIGNAL(error(QRadioTuner::Error)), this, SLOT(error(QRadioTuner::Error)));

     if(radio->isBandSupported(QRadioTuner::FM))
         radio->setBand(QRadioTuner::FM);

     QWidget *window = new QWidget;
     QVBoxLayout* layout = new QVBoxLayout;
     QHBoxLayout* buttonBar = new QHBoxLayout;
 #if defined Q_OS_SYMBIAN // this is so that we can see all buttons also in 3.1 devices, where the screens are smaller..
     QHBoxLayout* buttonBar2 = new QHBoxLayout;
 #endif
     QHBoxLayout* topBar = new QHBoxLayout;

     layout->addLayout(topBar);

     freq = new QLabel;
     freq->setText(QString("%1 kHz").arg(radio->frequency()/1000));
     topBar->addWidget(freq);

     signal = new QLabel;
     if (radio->isAvailable())
         signal->setText(tr("No Signal"));
     else
         signal->setText(tr("No radio found"));
     topBar->addWidget(signal);
 #if defined Q_WS_MAEMO_5
     QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
     topBar->addItem(spacer);
     volumeSlider = new QSlider(Qt::Horizontal,this);
 #else
     volumeSlider = new QSlider(Qt::Vertical,this);
 #endif
     volumeSlider->setRange(0,100);
     volumeSlider->setValue(50);
     connect(volumeSlider,SIGNAL(valueChanged(int)),this,SLOT(updateVolume(int)));
     topBar->addWidget(volumeSlider);

     layout->addLayout(buttonBar);
 #if defined Q_OS_SYMBIAN
     layout->addLayout(buttonBar2);
 #endif

     searchLeft = new QPushButton;
     searchLeft->setText(tr("scan Down"));
     connect(searchLeft,SIGNAL(clicked()),SLOT(searchDown()));
     buttonBar->addWidget(searchLeft);

     left = new QPushButton;
     left->setText(tr("Freq Down"));
     connect(left,SIGNAL(clicked()),SLOT(freqDown()));
 #if defined Q_OS_SYMBIAN
     buttonBar2->addWidget(left);
 #else
     buttonBar->addWidget(left);
 #endif

     right = new QPushButton;
     connect(right,SIGNAL(clicked()),SLOT(freqUp()));
     right->setText(tr("Freq Up"));
 #if defined Q_OS_SYMBIAN
     buttonBar2->addWidget(right);
 #else
     buttonBar->addWidget(right);
 #endif

     searchRight = new QPushButton;
     searchRight->setText(tr("scan Up"));
     connect(searchRight,SIGNAL(clicked()),SLOT(searchUp()));
     buttonBar->addWidget(searchRight);

     window->setLayout(layout);
     setCentralWidget(window);
     window->show();

     radio->start();
 }

 Radio::~Radio()
 {
 }

 void Radio::freqUp()
 {
     int f = radio->frequency();
     f = f + radio->frequencyStep(QRadioTuner::FM);
     radio->setFrequency(f);
 }

 void Radio::freqDown()
 {
     int f = radio->frequency();
     f = f - radio->frequencyStep(QRadioTuner::FM);
     radio->setFrequency(f);
 }

 void Radio::searchUp()
 {
     radio->searchForward();
 }

 void Radio::searchDown()
 {
     radio->searchBackward();
 }

 void Radio::freqChanged(int)
 {
     freq->setText(QString("%1 kHz").arg(radio->frequency()/1000));
 }

 void Radio::signalChanged(int)
 {
     if(radio->signalStrength() > 25)
         signal->setText(tr("Got Signal"));
     else
         signal->setText(tr("No Signal"));
 }

 void Radio::updateVolume(int v)
 {
     radio->setVolume(v);
 }

 void Radio::error(QRadioTuner::Error error)
 {
     const QMetaObject* metaObj = radio->metaObject();
     QMetaEnum errorEnum = metaObj->enumerator(metaObj->indexOfEnumerator("Error"));
     qWarning().nospace() << "Warning: Example application received error QRadioTuner::" << errorEnum.valueToKey(error);
 }
