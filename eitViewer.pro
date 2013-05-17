#-------------------------------------------------
#
# Project created by QtCreator 2012-12-05T12:02:47
#
#-------------------------------------------------

QT       += core widgets opengl network

TARGET = eitViewer
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    measurementsystem.cpp \
    solver.cpp

HEADERS  += mainwindow.h \
    image.h \
    measurementsystem.h \
    solver.h

FORMS    += mainwindow.ui

CONFIG += c++11

macx {
    QMAKE_CXXFLAGS += -stdlib=libc++
    QMAKE_LIBS += -lc++
    QMAKE_LIBS += -Xlinker -rpath /usr/local/cuda/lib
    QMAKE_CXXFLAGS += -mmacosx-version-min=10.7
}

unix:!symbian: LIBS += -L/usr/local/cuda/lib -lcudart -lcublas -ldl

INCLUDEPATH += /usr/local/cuda/include
DEPENDPATH += /usr/local/cuda/include

unix:!symbian: LIBS += -L/usr/local/lib -lfasteit

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
