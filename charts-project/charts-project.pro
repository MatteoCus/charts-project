QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clonable.cpp \
    cycling.cpp \
    endurance.cpp \
    exercise.cpp \
    main.cpp \
    mainwindow.cpp \
    plan.cpp \
    repetition.cpp \
    rugby.cpp \
    run.cpp \
    tennis.cpp \
    training.cpp \
    walk.cpp

HEADERS += \
    clonable.h \
    cycling.h \
    endurance.h \
    exercise.h \
    mainwindow.h \
    plan.h \
    repetition.h \
    rugby.h \
    run.h \
    tennis.h \
    training.h \
    walk.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
