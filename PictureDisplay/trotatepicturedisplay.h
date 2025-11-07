#pragma once

#ifndef _TROTATEPICTUREDISPLAY_H_
#define _TROTATEPICTUREDISPLAY_H_

#include "tpicturedisplayabstract.h"
#include <memory>
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class TRotatePictureDisplayClass; };
QT_END_NAMESPACE

namespace cv
{
	class Mat;
};

class TRotatePictureDisplay : public TPictureDisplayAbstract
{
	Q_OBJECT

private:
	TPictureDisplayAbstract* pictureWidget;

	std::unique_ptr<cv::Mat> pixmap;
	cv::Size size;
	double angle;
	double scale;
	cv::InterpolationFlags interpolationFlags;
	cv::Vec4b borderColor;

	void paintPixmap();

public:
	TRotatePictureDisplay(QWidget* parent = nullptr);
	~TRotatePictureDisplay();

	void setPictureDisplayWidget(TPictureDisplayAbstract* widget);
	TPictureDisplayAbstract* pictureDisplayWidget();

	// 通过 TPictureDisplayAbstract 继承
	virtual void setPixmap(const QPixmap& pixmap) override;
	virtual QSize getPixmapSize() override;
	const cv::Mat* getPixmap();

	void setSize(cv::Size size);
	cv::Size getSize();

	void setAngle(double angle);
	double getAngle();

	void setScale(double scale);
	double getScale();

	void setInterpolationFlags(cv::InterpolationFlags interpolationFlags);
	cv::InterpolationFlags getInterpolationFlags();

	void setBorderColor(cv::Vec4b borderColor);
	cv::Vec4b getBorderColor();

signals:
	void pixmapChanged(const cv::Mat* pixmap);

	void sizeChanged(cv::Size size);
	void angleChanged(double angle);
	void scaleChanged(double scale);
	void interpolationFlagsChanged(cv::InterpolationFlags interpolationFlags);
	void borderColorChanged(cv::Vec4b borderColor);

private:
	Ui::TRotatePictureDisplayClass* ui;
};

#endif // !_TROTATEPICTUREDISPLAY_H_
