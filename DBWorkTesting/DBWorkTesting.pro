#-------------------------------------------------
#
# Project created by QtCreator 2017-11-14T08:38:14
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBWorkTesting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    universitymodel.cpp \
    peoplemodel.cpp \
    countrymodel.cpp \
    regionmodel.cpp \
    districtmodel.cpp \
    citymodel.cpp

HEADERS  += mainwindow.h \
    universitymodel.h \
    peoplemodel.h \
    countrymodel.h \
    regionmodel.h \
    districtmodel.h \
    citymodel.h

FORMS    += mainwindow.ui
