/********************************************************************************
** Form generated from reading UI file 'audiorecorder.ui'
**
** Created: Fri Jan 17 14:45:45 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIORECORDER_H
#define UI_AUDIORECORDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioRecorder
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *audioDeviceBox;
    QLabel *label_2;
    QComboBox *audioCodecBox;
    QLabel *label_3;
    QComboBox *containerBox;
    QLabel *label_4;
    QComboBox *sampleRateBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *constantQualityRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QSlider *qualitySlider;
    QRadioButton *constantBitrateRadioButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *bitrateBox;
    QPushButton *outputButton;
    QPushButton *recordButton;
    QPushButton *pauseButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AudioRecorder)
    {
        if (AudioRecorder->objectName().isEmpty())
            AudioRecorder->setObjectName(QString::fromUtf8("AudioRecorder"));
        AudioRecorder->resize(297, 374);
        centralwidget = new QWidget(AudioRecorder);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        audioDeviceBox = new QComboBox(centralwidget);
        audioDeviceBox->setObjectName(QString::fromUtf8("audioDeviceBox"));

        gridLayout_2->addWidget(audioDeviceBox, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        audioCodecBox = new QComboBox(centralwidget);
        audioCodecBox->setObjectName(QString::fromUtf8("audioCodecBox"));

        gridLayout_2->addWidget(audioCodecBox, 1, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        containerBox = new QComboBox(centralwidget);
        containerBox->setObjectName(QString::fromUtf8("containerBox"));

        gridLayout_2->addWidget(containerBox, 2, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        sampleRateBox = new QComboBox(centralwidget);
        sampleRateBox->setObjectName(QString::fromUtf8("sampleRateBox"));

        gridLayout_2->addWidget(sampleRateBox, 3, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        constantQualityRadioButton = new QRadioButton(groupBox);
        constantQualityRadioButton->setObjectName(QString::fromUtf8("constantQualityRadioButton"));
        constantQualityRadioButton->setChecked(true);

        gridLayout->addWidget(constantQualityRadioButton, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        qualitySlider = new QSlider(groupBox);
        qualitySlider->setObjectName(QString::fromUtf8("qualitySlider"));
        qualitySlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(qualitySlider, 1, 1, 1, 1);

        constantBitrateRadioButton = new QRadioButton(groupBox);
        constantBitrateRadioButton->setObjectName(QString::fromUtf8("constantBitrateRadioButton"));

        gridLayout->addWidget(constantBitrateRadioButton, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        bitrateBox = new QComboBox(groupBox);
        bitrateBox->setObjectName(QString::fromUtf8("bitrateBox"));
        bitrateBox->setEnabled(false);

        gridLayout->addWidget(bitrateBox, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 3);

        outputButton = new QPushButton(centralwidget);
        outputButton->setObjectName(QString::fromUtf8("outputButton"));

        gridLayout_3->addWidget(outputButton, 2, 0, 1, 1);

        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));

        gridLayout_3->addWidget(recordButton, 2, 1, 1, 1);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setEnabled(false);

        gridLayout_3->addWidget(pauseButton, 2, 2, 1, 1);

        AudioRecorder->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AudioRecorder);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AudioRecorder->setStatusBar(statusbar);

        retranslateUi(AudioRecorder);
        QObject::connect(constantQualityRadioButton, SIGNAL(toggled(bool)), qualitySlider, SLOT(setEnabled(bool)));
        QObject::connect(constantBitrateRadioButton, SIGNAL(toggled(bool)), bitrateBox, SLOT(setEnabled(bool)));
        QObject::connect(outputButton, SIGNAL(clicked()), AudioRecorder, SLOT(setOutputLocation()));
        QObject::connect(recordButton, SIGNAL(clicked()), AudioRecorder, SLOT(toggleRecord()));
        QObject::connect(pauseButton, SIGNAL(clicked()), AudioRecorder, SLOT(togglePause()));

        QMetaObject::connectSlotsByName(AudioRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *AudioRecorder)
    {
        AudioRecorder->setWindowTitle(QApplication::translate("AudioRecorder", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AudioRecorder", "Input Device:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AudioRecorder", "Audio Codec:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AudioRecorder", "File Container:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AudioRecorder", "Sample rate:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AudioRecorder", "Encoding Mode:", 0, QApplication::UnicodeUTF8));
        constantQualityRadioButton->setText(QApplication::translate("AudioRecorder", "Constant Quality:", 0, QApplication::UnicodeUTF8));
        constantBitrateRadioButton->setText(QApplication::translate("AudioRecorder", "Constant Bitrate:", 0, QApplication::UnicodeUTF8));
        outputButton->setText(QApplication::translate("AudioRecorder", "Output...", 0, QApplication::UnicodeUTF8));
        recordButton->setText(QApplication::translate("AudioRecorder", "Record", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QApplication::translate("AudioRecorder", "Pause", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AudioRecorder: public Ui_AudioRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIORECORDER_H
