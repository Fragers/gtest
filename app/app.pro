TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle
#CONFIG -= qt



QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
QT       += core gui
QT += network #charts


HEADERS += \
    createnewfile.h \
#    donutbreakdownchart.h \
    first_test.h \
    httpserver.h \
    initstart.h \
#    mainslice.h \
    savedia.h \
    #    chart.h \
    mainwindow.h \
        #myserver.h \
    treeitem.h \
    treemodel.h
      #  widget.h
SOURCES += \
    createnewfile.cpp \
#    donutbreakdownchart.cpp \
    httpserver.cpp \
    initstart.cpp \
#    mainslice.cpp \
    savedia.cpp \
    #chart.cpp \
    main.cpp \
    mainwindow.cpp \
    #myserver.cpp \
    treeitem.cpp \
    treemodel.cpp
    #widget.cpp
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



FORMS += \
#    chart.ui \
    createnewfile.ui \
    initstart.ui \
    mainwindow.ui \
    savedia.ui
    #widget.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

#INSTALLS += target
RESOURCES += \
    simpletreemodel.qrc

