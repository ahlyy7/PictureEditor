#pragma once

#ifndef _FREECOMPRESSIONPROCESS_H_
#define _FREECOMPRESSIONPROCESS_H_

#include "abstractimageprocess.h"
#include <QSize>
#include <opencv2/opencv.hpp>

class FreeCompressionProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	double compressibility;
	int width;
	int height;
	cv::InterpolationFlags interpolationFlags;

	//	假设image指针不为空的情况下，设置缩放后的大小
	void setSizeFromCompressibility();
	//	假设image指针不为空的情况下，设置缩放后的大小
	void setSize(int width, int height, bool emitCompressibilityChanged = true);

protected:
	virtual void process() override;
	virtual void resetArgAfterImageChanged() override;

public:
	static const cv::InterpolationFlags initializeInterpolationFlags;

	FreeCompressionProcess(QObject* parent = nullptr);
	virtual ~FreeCompressionProcess() override;

	// 通过 AbstractImageProcess 继承
	bool processable() override;
	virtual bool resetable() override;
	QString processName() override;
	void resetArg() override;

	void setCompressibility(double compressibility);
	double getCompressibility();

	void setWidth(int width);
	int getWidth();

	void setHeight(int height);
	int getHeight();

	QSize getSize();

	void setInterpolationFlags(cv::InterpolationFlags interpolationFlags);
	cv::InterpolationFlags getInterpolationFlags();

signals:
	void compressibilityChanged(double compressibility);

	void widthChanged(int width);
	void heightChanged(int height);
	void sizeChanged(QSize size);

	void interpolationFlagsChanged(cv::InterpolationFlags interpolationFlags);
};

#endif // !_FREECOMPRESSIONPROCESS_H_
