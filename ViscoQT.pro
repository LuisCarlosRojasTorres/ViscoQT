QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DlgAbout.cpp \
    DlgNewMaterial.cpp \
    LinearViscoelasticMaterial.cpp \
    main.cpp \
    MainWindow.cpp \
    qcustomplot.cpp

HEADERS += \
    DlgAbout.h \
    DlgNewMaterial.h \
    LinearViscoelasticMaterial.h \
    MainWindow.h \
    qcustomplot.h

FORMS += \
    DlgAbout.ui \
    DlgNewMaterial.ui \
    MainWindow.ui

INCLUDEPATH += "C:\RedTowerLibs\eigen-3.4.0"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
