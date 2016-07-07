#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T14:15:24
#
#-------------------------------------------------
include(../defaults.pri)

QT       += sql testlib

QT       -= gui


TARGET = tst_invcontrollertests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_invcontrollertests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

#LIBS += -L../invModel/debug -l invModel
#LIBS += -L../invController/debug -l invController

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../invController/release/ -linvController
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../invController/debug/ -linvController
else:unix: LIBS += -L$$OUT_PWD/../invController/ -linvController

INCLUDEPATH += $$PWD/../invController
DEPENDPATH += $$PWD/../invController

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invController/release/libinvController.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invController/debug/libinvController.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invController/release/invController.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../invController/debug/invController.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../invController/libinvController.a


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
