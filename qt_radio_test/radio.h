#ifndef RADIO_H
 #define RADIO_H

 #include <QtGui>

 #include <qradiotuner.h>

 class QLabel;
 class QPushButton;
 class QSlider;

 QT_USE_NAMESPACE

 class Radio : public QMainWindow
 {
     Q_OBJECT
 public:
     Radio();
     ~Radio();

 public slots:
     void freqUp();
     void freqDown();
     void searchUp();
     void searchDown();
     void freqChanged(int f);
     void signalChanged(int s);
     void updateVolume(int v);
     void error(QRadioTuner::Error error);

 private:
     QLabel* freq;
     QLabel* signal;
     QPushButton* left;
     QPushButton* right;
     QPushButton* searchLeft;
     QPushButton* searchRight;
     QSlider* volumeSlider;
     QRadioTuner* radio;
 };

 #endif
