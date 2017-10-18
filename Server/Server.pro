QT += core
QT -= gui

CONFIG += c++11

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bcm2835_stub.cpp \
    pin.c \
    inputpin.c \
    outputpin.c

HEADERS += \
    bcm2835.h \
    pin.h \
    inputpin.h \
    outputpin.h
