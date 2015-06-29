#-------------------------------------------------
#
# Project created by QtCreator 2012-03-21T22:01:54
#
#-------------------------------------------------
QT += gui declarative
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tile.cpp \
    validation.cpp \
    board.cpp \
    loadgame.cpp

HEADERS  += mainwindow.h \
    tile.h \
    validation.h \
    firstwindow.h \
    loadgame.h

FORMS    += mainwindow.ui

RESOURCES += \
    Images.qrc
