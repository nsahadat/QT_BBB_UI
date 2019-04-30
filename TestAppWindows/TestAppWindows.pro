#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T14:33:23
#
#-------------------------------------------------
QT       += core gui
#QT       += core gui serialport

CONFIG  += serialport

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestAppWindows
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#INCLUDEPATH += C:/armadillo/include

LIBS += -llapack -lblas -larmadillo

#LIBS += \
 #       -LC:/armadillo/lib_win64 \
  #      -lblas_win64_MT \
   #     -llapack_win64_MT


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    waveforms.cpp \
    qcustomplot.cpp \
    sensdata.cpp \
    calibration.cpp \
    train.cpp \
    testing.cpp \
    svm.cpp \
    pwc.cpp \
    PWC_Drive.cpp \
    SimpleGPIO.cpp


HEADERS += \
        mainwindow.h \
    waveforms.h \
    qcustomplot.h \
    sensdata.h \
    calibration.h \
    train.h \
    testing.h \
    svm.h \
    pwc.h \
    PWC_Drive.h \
    SimpleGPIO.h

FORMS += \
        mainwindow.ui \
    waveforms.ui \
    calibration.ui \
    train.ui \
    testing.ui \
    pwc.ui



