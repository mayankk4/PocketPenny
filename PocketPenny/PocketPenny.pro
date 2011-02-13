#-------------------------------------------------
#
# Project created by QtCreator 2011-02-12T08:57:07
#
#-------------------------------------------------

QT       += core \
            sql

QT       -= gui

TARGET = PocketPenny

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    persistantmanager.cpp \
    Category.cpp \
    Expense.cpp


HEADERS += ProfileInfo.h \
    persistantmanager.h \
    ProfileInfo.h \
    Category.h \
    Expense.h
