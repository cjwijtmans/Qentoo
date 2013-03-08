#-------------------------------------------------
#
# Project created by QtCreator 2013-03-04T04:35:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qentoo
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Repository.cpp \
    Portage.cpp \
    RepositoryParser.cpp \
    PackageParser.cpp \
    PortageParser.cpp

HEADERS  += MainWindow.hpp \
    Repository.hpp \
    Portage.hpp \
    RepositoryParser.hpp \
    PackageParser.hpp \
    PortageParser.hpp

FORMS    += MainWindow.ui
