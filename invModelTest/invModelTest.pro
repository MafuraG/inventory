#-------------------------------------------------
#
# Project created by QtCreator 2016-06-17T13:00:35
#
#-------------------------------------------------
include(../defaults.pri)

QT       += testlib

QT       -= gui

TARGET = tst_invmodeltest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_invmodeltest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../invModel/debug -l invModel
