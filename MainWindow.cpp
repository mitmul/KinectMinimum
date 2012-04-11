#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_KinectStart_clicked()
{
	kinect.init();
	boost::thread kinectTh(bind(&MainWindow::getKinectData, this));
}

void MainWindow::getKinectData()
{
	while(1)
	{
		try
		{
			kinect.updateKinect();

			// デプス画像
			XnDepthPixel *depth_pixel = kinect.getDepth();
			Mat depth_image(480, 640, CV_16SC1, depth_pixel);
			Mat depth_show;
			depth_image.convertTo(depth_show, CV_8U, 255.0 / 8192.0);

			// スケルトン
			vector<vector<XnPoint3D> > skeleton = kinect.getSkeleton();
			if(!skeleton.empty())
			{
				for(int i = 0; i < skeleton.size(); ++i)
				{
					for(int j = 0; j < skeleton.at(i).size(); ++j)
					{
						Point pos(skeleton.at(i).at(j).X, skeleton.at(i).at(j).Y);
						putText(depth_show, lexical_cast<string>(j), pos, FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255));
						circle(depth_show, pos, 5, Scalar(255), -1);
					}
				}
			}

			imshow("depth", depth_show);

			// RGB画像
			XnUInt8 *image_pixel = kinect.getImage();
			Mat rgb_image(480, 640, CV_8UC3, image_pixel);
			cvtColor(rgb_image, rgb_image, CV_BGR2RGB);

			imshow("rgb", rgb_image);
		}
		catch(std::exception &e)
		{
			cerr << "getDepth" << endl
				 << e.what() << endl;
		}
	}
}
