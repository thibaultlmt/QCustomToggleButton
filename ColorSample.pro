#-------------------------------------------------
#
# Project created by QtCreator 2022-06-23T15:02:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = ColorSample
TEMPLATE = app


#Destination directory
DESTDIR = $$_PRO_FILE_PWD_/bin

#Moc directory
MOC_DIR = $$_PRO_FILE_PWD_/moc

#Objects directory
OBJECTS_DIR = $$_PRO_FILE_PWD_/obj


SOURCES += main.cpp\
        Dialog.cpp \
    QCustomToggleButton.cpp

HEADERS  += Dialog.h \
    QCustomToggleButton.h
