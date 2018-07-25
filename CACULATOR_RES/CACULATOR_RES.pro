#-------------------------------------------------
#
# Project created by QtCreator 2018-01-14T14:53:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CACULATOR_RES
TEMPLATE = app


SOURCES += main.cpp \
    caculatorui.cpp \
    caculatordec.cpp

HEADERS  += \
    caculatorui.h \
    caculatordec.h

FORMS    +=
RC_ICONS =1.ico

DISTFILES += \
    css.qss

RESOURCES += \
    caculator.qrc
