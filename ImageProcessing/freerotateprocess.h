#pragma once

#ifndef _FREEROTATEPROCESS_H_
#define _FREEROTATEPROCESS_H_

#include "abstractimageprocess.h"
#include <opencv2/opencv.hpp>

class FreeRotateProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	cv::Size size;
	double angle;
	double scale;
	cv::InterpolationFlags interpolationFlags;
	cv::Vec4b borderColor;

	bool scaleChangedReJudge;

protected:
	virtual void process() override;
	//virtual void resetArgAfterImageChanged() override;

public:
	FreeRotateProcess(QObject* parent = nullptr);
	~FreeRotateProcess();

	static const cv::InterpolationFlags initializeInterpolationFlags;
	static const cv::Vec4b initializeBorderColor;
	static void rotate(cv::Mat* mat, double angle, double scale, cv::Size size, cv::InterpolationFlags interpolationFlags, cv::Vec4b borderColor);

	// 通过 AbstractImageProcess 继承
	virtual bool processable() override;
	virtual bool resetable() override;
	virtual QString processName() override;
	virtual void resetArg() override;

	void setSize(cv::Size size);
	cv::Size getSize();

	std::pair<int, int> minmaximumWidthAndHeight();

	int minimumWidthAndHeight();
	int maximumWidthAndHeight();

	void setAngle(double angle);
	double getAngle();

	void setScale(double scale);
	double getScale();

	std::pair<double, double> minmaximumScale();

	double minimumScale();
	double maximumScale();

	void setInterpolationFlags(cv::InterpolationFlags interpolationFlags);
	cv::InterpolationFlags getInterpolationFlags();

	void setBorderColor(cv::Vec4b borderColor);
	cv::Vec4b getBorderColor();

signals:
	void sizeChanged(cv::Size size);
	void angleChanged(double angle);
	void scaleChanged(double scale);
	void interpolationFlagsChanged(cv::InterpolationFlags interpolationFlags);
	void borderColorChanged(cv::Vec4b borderColor);
};

#endif // !_FREEROTATEPROCESS_H_
