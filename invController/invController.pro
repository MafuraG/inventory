#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T15:52:53
#
#-------------------------------------------------
include(../defaults.pri)

QT       -= gui

TARGET = invController
TEMPLATE = lib
CONFIG += staticlib

SOURCES += invcontroller.cpp

HEADERS += invcontroller.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -L../invModel/debug -l invModel
