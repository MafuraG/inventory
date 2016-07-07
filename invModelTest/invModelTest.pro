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

#LIBS += -L../invModel/debug -l invModel


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../invModel/release/ -linvModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../invModel/debug/ -linvModel
else:unix: LIBS += -L$$OUT_PWD/../invModel/ -linvModel

INCLUDEPATH += $$PWD/../invModel
DEPENDPATH += $$PWD/../invModel

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invModel/release/libinvModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invModel/debug/libinvModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invModel/release/invModel.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invModel/debug/invModel.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../invModel/libinvModel.a
