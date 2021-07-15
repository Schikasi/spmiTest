QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseClasses/baseanswer.cpp \
    BaseClasses/basequest.cpp \
    BaseClasses/basetest.cpp \
    BaseClasses/basetestreport.cpp \
    BaseClasses/baseuseranswer.cpp \
    Testing/answer.cpp \
    Testing/question.cpp \
    Testing/test.cpp \
    Widgets/oneofwidget.cpp \
    Widgets/testreportwidget.cpp \
    answerMaker.cpp \
    main.cpp \
    mainwindow.cpp \
    #question.cpp \
    simpleanswer.cpp \
    simplenavigateview.cpp \
    simplequest.cpp \
    simpletestreport.cpp \
    simpletestview.cpp \
    simpleuseranswer.cpp \
    textedit.cpp \
    xmltest.cpp

HEADERS += \
    BaseClasses/baseanswer.h \
    BaseClasses/basequest.h \
    BaseClasses/basetest.h \
    BaseClasses/basetestreport.h \
    BaseClasses/baseuseranswer.h \
    Interfaces/baseanswer.h \
    Testing/answer.h \
    Testing/question.h \
    Testing/test.h \
    Widgets/oneofwidget.h \
    Widgets/testreportwidget.h \
    answerMaker.h \
    mainwindow.h \
    #question.h \
    simpleanswer.h \
    simplenavigateview.h \
    simplequest.h \
    simpletestreport.h \
    simpletestview.h \
    simpleuseranswer.h \
    textedit.h \
    xmltest.h

FORMS += \
    Widgets/oneofwidget.ui \
    Widgets/testreportwidget.ui \
    mainwindow.ui \
    simplenavigateview.ui \
    simpletestview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
