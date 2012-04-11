#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "KinectControl.h"

using namespace cv;
using namespace boost;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_KinectStart_clicked();

private:
	Ui::MainWindow *ui;
	KinectControl kinect;

	void getKinectData();
};

#endif // MAINWINDOW_H
