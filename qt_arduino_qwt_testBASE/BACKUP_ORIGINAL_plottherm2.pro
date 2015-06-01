#-------------------------------------------------
#
# Project created by QtCreator 2011-06-19T19:43:01
#
#-------------------------------------------------

QT       += core gui

TARGET = plottherm2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

#uncomment this part to display the console window (then you have to recompile all your project)
#CONFIG      += console

#this is the commands you have to add :
#-the port com library :
INCLUDEPATH += C:/Qt/qextserialport-1.2win-alpha/
LIBS +=  C:\Qt\qextserialport-1.2win-alpha\build\libqextserialportd.a
#-the graphic library :
INCLUDEPATH += C:\Qt\qwt-6.0.0\src
LIBS += C:\Qt\qwt-6.0.0\lib\libqwt.a
