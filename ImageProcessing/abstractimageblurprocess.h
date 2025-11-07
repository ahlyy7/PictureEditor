#pragma once

#ifndef _ABSTRACTIMAGEBLURPROCESS_H_
#define _ABSTRACTIMAGEBLURPROCESS_H_

#include "abstractimageprocess.h"
#include <opencv2/opencv.hpp>

class AbstractImageBlurProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	cv::Size ksize;

public:
	static const cv::Size initializeKsize;

	AbstractImageBlurProcess(QObject* parent);
	~AbstractImageBlurProcess();

	bool processable() override;
	bool resetable() override;
	void resetArg() override;

	void setKsize(cv::Size ksize);
	cv::Size getKsize();

signals:
	void ksizeChanged(cv::Size ksize);
};

#endif // !_ABSTRACTIMAGEBLURPROCESS_H_
