######################################################################
# Automatically generated by qmake (2.01a) jeu. nov. 7 08:27:50 2013
######################################################################

# usually works without, why not give it a try. after test, does nothing more/less
#QT += core gui

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += arduinoqwtwidget.h
SOURCES += arduinoqwtwidget.cpp main.cpp

# now using symbolic links to link against the qwt library
# sudo ln -s /usr/local/qwt-6.1.0/include/ /usr/include/qwt
# sudo ln -s /usr/local/qwt-6.1.0/lib/ /usr/lib/qwt

# now using a more simpler way of installing the library:
# sudo apt-get install libqwt-dev
CONFIG += extserialport qwt
#CONFIG += extserialport

# to display the console window
CONFIG += console

# manually add the pathes to the qwt lib -> throw compilation errors
#INCLUDEPATH += /home/stephaneag/Documents/Development/3rd_party_libs/qwt-6.1.0/src
#LIBS += /home/stephaneag/Documents/Development/3rd_party_libs/qwt-6.1.0/lib/libqwt.so

# sudo apt-get install libqwt5-qt4-dev -> throw compilation errors
#INCLUDEPATH += /usr/include/qwt-qt4
#LIBS += -l qwt-qt4
