QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/cycling.cpp \
    Model/endurance.cpp \
    Model/exercise.cpp \
    Model/exercisecreator.cpp \
    Model/model.cpp \
    Model/timespan.cpp \
    main.cpp \
    mainwindow.cpp \
    Model/plan.cpp \
    Model/repetition.cpp \
    Model/rugby.cpp \
    Model/run.cpp \
    Model/tennis.cpp \
    Model/training.cpp \
    Model/walk.cpp

HEADERS += \
    Model/action.h \
    Model/cycling.h \
    Model/endurance.h \
    Model/exercise.h \
    Model/exercisecreator.h \
    Model/model.h \
    Model/timespan.h \
    mainwindow.h \
    Model/plan.h \
    Model/repetition.h \
    Model/rugby.h \
    Model/run.h \
    Model/tennis.h \
    Model/training.h \
    Model/walk.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
