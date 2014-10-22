TEMPLATE = app
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    MovieType.cpp \
    SortedMovieList.cpp \
    Menu.cpp

HEADERS += \
    SortedMovieList.h \
    MovieType.h \
    Menu.h

