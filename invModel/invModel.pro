#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T10:14:09
#
#-------------------------------------------------

QT       -= gui

TARGET = invModel
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    dbentity.cpp \
    organisation.cpp \
    inventory.cpp \
    journal.cpp \
    manufacturer.cpp \
    inventorytype.cpp \
    inventorystatus.cpp \
    inventoryItem.cpp

HEADERS += \
    dbentity.h \
    organisation.h \
    inventory.h \
    journal.h \
    manufacturer.h \
    inventorytype.h \
    inventorystatus.h \
    inventoryItem.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
