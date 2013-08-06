#-------------------------------------------------
#
# Project created by QtCreator 2013-08-06T16:15:40
#
#-------------------------------------------------

QT       += core gui
win32 {
QMAKE_LFLAGS += -static-libgcc
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReparseDeleter
TEMPLATE = app


SOURCES += main.cpp\
        reparsedeleter.cpp

HEADERS  += reparsedeleter.h

FORMS    += reparsedeleter.ui
