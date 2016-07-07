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


SOURCES += \
    datacontext.cpp \
    sqldatacontext.cpp \
    dataconverter.cpp \
    sqlitedataconverter.cpp \
    dbentitytablemodel.cpp \
    inventorytablemodel.cpp \
    jounaltablemodel.cpp \
    inventorycontroller.cpp

HEADERS += \
    datacontext.h \
    sqldatacontext.h \
    dataconverter.h \
    sqlitedataconverter.h \
    dbentitytablemodel.h \
    inventorytablemodel.h \
    jounaltablemodel.h \
    inventorycontroller.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -L../invModel/debug -l invModel
