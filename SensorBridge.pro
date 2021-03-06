TEMPLATE = app

QT += widgets serialport websockets charts
CONFIG += c++11

TARGET=SensorBridge

SOURCES += main.cpp \
    core/sensor.cpp \
    core/serialconnection.cpp \
    core/sensoroutput.cpp \
    core/websocketoutput.cpp \
    ui/mainwindow.cpp \
    ui/websocketsettingswidget.cpp \
    ui/outputsettingswidget.cpp \
    ui/csvfilesettingswidget.cpp \
    ui/sensorwidget.cpp \
    ui/settingsdialog.cpp \
    core/csvfileoutput.cpp \
    core/jsonfileoutput.cpp \
    ui/jsonfilesettingswidget.cpp \
    ui/uisensor.cpp \
    core/bridgeengine.cpp \
    core/sensoroutputformatter.cpp \
    core/smoothing/simplemovingaveragesmoothing.cpp \
    core/smoothing/exponentialsmoothing.cpp \
    core/smoothing/smoothing.cpp \
    core/smoothing/nonesmoothing.cpp

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    core/sensor.h \
    core/serialconnection.h \
    core/sensoroutput.h \
    core/websocketoutput.h \
    core/sensoroutputformatter.h \
    ui/mainwindow.h \
    ui/websocketsettingswidget.h \
    ui/outputsettingswidget.h \
    ui/csvfilesettingswidget.h \
    ui/sensorwidget.h \
    ui/settingsdialog.h \
    core/csvfileoutput.h \
    core/jsonfileoutput.h \
    ui/jsonfilesettingswidget.h \
    ui/uisensor.h \
    core/bridgeengine.h \
    core/smoothing/simplemovingaveragesmoothing.h \
    core/smoothing/exponentialsmoothing.h \
    core/smoothing/smoothing.h \
    core/smoothing/nonesmoothing.h

DEFINES += SERIAL_ANALOG_SENSORS=3

RC_ICONS = icon.ico
ICON = icon.icns

