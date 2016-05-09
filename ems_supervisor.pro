QT += core
QT -= gui

CONFIG += c++11

TARGET = ems_supervisor
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    libmodbus/src/modbus.c \
    libmodbus/src/modbus-data.c \
    libmodbus/src/modbus-rtu.c \
    libmodbus/src/modbus-tcp.c \
    libmodbus/src/modbus-ascii.c \
    libmodbus/src/modbus.h \
    modbus_communicator.cpp

HEADERS += \
    libmodbus/src/modbus.h \
    imodbus.h \
    imodbus.h \
    modbus_communicator.h


INCLUDEPATH += libmodbus \
               libmodbus/src

unix {

    DEFINES += _TTY_POSIX_
}

win32 {

    DEFINES += _TTY_WIN_  WINVER=0x0501
    LIBS += -lsetupapi -lws2_32
}

