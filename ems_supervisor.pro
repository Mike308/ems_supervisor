QT += core
QT+=sql
QT -= gui

CONFIG += c++11

TARGET = ems_supervisor
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
include(3rdparty/qextserialport/src/qextserialport.pri)
SOURCES += main.cpp \
           ems_supervisor_main_class.cpp \
           ems_database.cpp

HEADERS += ems_supervisor_main_class.h \
           ems_database.h


INCLUDEPATH += libmodbus \
               libmodbus/src



