#ifndef AUDIOOUTPUT_H
 #define AUDIOOUTPUT_H

 #include <math.h>

 #include <QObject>
 #include <QMainWindow>
 #include <QIODevice>
 #include <QTimer>
 #include <QPushButton>
 #include <QComboBox>
 #include <QByteArray>

 #include <QAudioOutput>

 class Generator : public QIODevice
 {
     Q_OBJECT
 public:
     Generator(const QAudioFormat &format, qint64 durationUs, int frequency, QObject *parent);
     ~Generator();

     void start();
     void stop();

     qint64 readData(char *data, qint64 maxlen);
     qint64 writeData(const char *data, qint64 len);
     qint64 bytesAvailable() const;

 private:
     void generateData(const QAudioFormat &format, qint64 durationUs, int frequency);

 private:
     qint64 m_pos;
     QByteArray m_buffer;
 };

 class AudioTest : public QMainWindow
 {
     Q_OBJECT
 public:
     AudioTest();
     ~AudioTest();

 private:
     void initializeWindow();
     void initializeAudio();
     void createAudioOutput();

 private:
     QTimer*          m_pullTimer;

     // Owned by layout
     QPushButton*     m_modeButton;
     QPushButton*     m_suspendResumeButton;
     QComboBox*       m_deviceBox;

     QAudioDeviceInfo m_device;
     Generator*       m_generator;
     QAudioOutput*    m_audioOutput;
     QIODevice*       m_output; // not owned
     QAudioFormat     m_format;

     bool             m_pullMode;
     QByteArray       m_buffer;

     static const QString PushModeLabel;
     static const QString PullModeLabel;
     static const QString SuspendLabel;
     static const QString ResumeLabel;

 private slots:
     void notified();
     void pullTimerExpired();
     void toggleMode();
     void toggleSuspendResume();
     void stateChanged(QAudio::State state);
     void deviceChanged(int index);
 };

 #endif
