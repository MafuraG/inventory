#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T15:52:53
#
#-------------------------------------------------
include(../defaults.pri)

QT       -= gui

QT      +=sql

TARGET = invController
TEMPLATE = lib
CONFIG += staticlib

SOURCES += invcontroller.cpp \
    datacontext.cpp \
    sqldatacontext.cpp \
    dataconverter.cpp \
    sqlitedataconverter.cpp \
    dbentitytablemodel.cpp

HEADERS += invcontroller.h \
    datacontext.h \
    sqldatacontext.h \
    dataconverter.h \
    sqlitedataconverter.h \
    dbentitytablemodel.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -L../invModel/debug -l invModel
