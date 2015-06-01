#ifndef AUDIORECORDER_H
 #define AUDIORECORDER_H

 #include <QtCore/qurl.h>
 #include <QtGui/qmainwindow.h>

 #include <qmediarecorder.h>

 namespace Ui {
     class AudioRecorder;
 }

 class QAudioCaptureSource;

 QT_USE_NAMESPACE

 class AudioRecorder : public QMainWindow
 {
     Q_OBJECT
 public:
     AudioRecorder(QWidget *parent = 0);
     ~AudioRecorder();

 private slots:
     void setOutputLocation();
     void togglePause();
     void toggleRecord();

     void updateState(QMediaRecorder::State);
     void updateProgress(qint64 pos);
     void displayErrorMessage();
     QUrl generateAudioFilePath();

 private:
     Ui::AudioRecorder *ui;

     QAudioCaptureSource* audiosource;
     QMediaRecorder* capture;
     QAudioEncoderSettings  audioSettings;
     bool outputLocationSet;

 };

 #endif
