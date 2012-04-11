#-------------------------------------------------
#
# Project created by QtCreator 2012-04-11T17:23:13
#
#-------------------------------------------------

QT       += core gui

TARGET = Kinect
TEMPLATE = app


SOURCES += main.cpp\
		MainWindow.cpp \
	KinectControl.cpp

HEADERS  += MainWindow.h \
	KinectControl.h

FORMS    += MainWindow.ui

# avin
LIBS += -L/usr/lib \
	-lXnDDK \
	-lXnDeviceFile \
	-lXnDeviceSensorV2KM \
	-lXnFormats \
	-lXnCore

# OpenNI & NITE
INCLUDEPATH += /usr/include/ni \
	/usr/include/nite
LIBS += -L/usr/lib \
	-lXnVFeatures_1_5_2 \
	-lXnVHandGenerator_1_5_2 \
	-lXnVCNITE_1_5_2 \
	-lXnVNite_1_5_2 \
	-lnimCodecs \
	-lnimMockNodes \
	-lnimRecorder \
	-lOpenNI

# OpenCV
INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib \
	-lopencv_stitching \
	-lopencv_ts \
	-lopencv_videostab \
	-lopencv_calib3d \
	-lopencv_contrib \
	-lopencv_features2d \
	-lopencv_flann \
	-lopencv_gpu \
	-lopencv_highgui \
	-lopencv_imgproc \
	-lopencv_legacy \
	-lopencv_ml \
	-lopencv_nonfree \
	-lopencv_objdetect \
	-lopencv_photo \
	-lopencv_video \
	-lopencv_core

# boost
INCLUDEPATH += /opt/local/include
LIBS += -L/opt/local/lib \
	-lboost_thread-mt
