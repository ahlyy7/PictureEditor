#pragma once

#ifndef _TPROCESSPICTUREDISPLAY_H_
#define _TPROCESSPICTUREDISPLAY_H_

#include "tmultilayerpicturedisplayabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TProcessPictureDisplayClass; };
QT_END_NAMESPACE

namespace cv
{
	class Mat;
};

class AbstractImageProcess;

class TProcessPictureDisplay : public TMultilayerPictureDisplayAbstract
{
	Q_OBJECT

private:
	std::unique_ptr<cv::Mat> image;
	std::unique_ptr<cv::Mat> imageCopy;

	//TPictureDisplayAbstract* pictureDisplay;
	AbstractImageProcess* imageProcess;

public:
	TProcessPictureDisplay(QWidget* parent = nullptr);
	~TProcessPictureDisplay();

	void repaintPixmap();

	// 通过 TPictureDisplayAbstract 继承
	void setPixmap(const QPixmap& pixmap) override;
	QSize getPixmapSize() override;

	//void setPictureDisplayWidget(TPictureDisplayAbstract* widget);
	//TPictureDisplayAbstract* pictureDisplayWidget();

	void setImageProcess(AbstractImageProcess* imageProcess);
	AbstractImageProcess* getImageProcess();

private slots:
	void imageProcessReJudge();

private:
	Ui::TProcessPictureDisplayClass* ui;
};

#endif // !_TPROCESSPICTUREDISPLAY_H_
