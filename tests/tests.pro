include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG += thread

QMAKE_CXXFLAGS += -Wall -Wextra #-Werror
QMAKE_CFLAGS += -Wall -Wextra #-Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/input/\\\" \
           SAVEDIR=\\\"$$PWD/TEST_SAVE/\\\" \
           OTHERDIR=\\\"$$PWD/OTHER_TESTS/\\\" \
           INDIR=\\\"$$PWD/inp/\\\" \
           DELETEDIR=\\\"$$PWD/deleteRow/\\\"

HEADERS += second_test.h \
    other_tests.h \
    simple_test.h \
    test_deleteRow.h \
    test_insertChild.h \
    test_save.h


SOURCES +=     main.cpp \
    ../app/myfunc.c

INCLUDEPATH += ../app

DISTFILES += \
    input/TestSTDOut_output.txt

QT       += core gui
QT += network charts

SOURCES += \
    ../app/chart.cpp \
    #../app/main.cpp \
    ../app/mainwindow.cpp \
    #myserver.cpp \
    ../app/treeitem.cpp \
    ../app/treemodel.cpp
    #widget.cpp

    HEADERS += \
        ../app/createnewfile.h \
        ../app/donutbreakdownchart.h \
        ../app/httpserver.h \
        ../app/initstart.h \
        ../app/mainslice.h \
        ../app/savedia.h

    SOURCES += \
        ../app/createnewfile.cpp \
        ../app/donutbreakdownchart.cpp \
        ../app/httpserver.cpp \
        ../app/initstart.cpp \
        ../app/mainslice.cpp \
        ../app/savedia.cpp

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


    HEADERS += \
        ../app/chart.h \
        ../app/mainwindow.h \
        #myserver.h \
        ../app/treeitem.h \
        ../app/treemodel.h
      #  widget.h

    FORMS += \
        ../app/chart.ui \
        ../app/createnewfile.ui \
       ../app/initstart.ui \
        ../app/mainwindow.ui \
        ../app/savedia.ui
        #widget.ui

    # Default rules for deployment.
    #qnx: target.path = /tmp/$${TARGET}/bin
    #else: unix:!android: target.path = /opt/$${TARGET}/bin
    #!isEmpty(target.path): INSTALLS += target

    #INSTALLS += target
    RESOURCES += \
        ../app/simpletreemodel.qrc
