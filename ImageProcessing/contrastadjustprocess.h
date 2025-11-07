#pragma once

#ifndef _ContrastAdjustProcess_H_
#define _ContrastAdjustProcess_H_

#include "abstractimageadjustprocess.h"

class ContrastAdjustProcess : public AbstractImageAdjustProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageAdjustProcess 继承
	void process() override;

public:
	static void adjustContrastCentered(cv::Mat* img, double alpha);

	ContrastAdjustProcess(QObject* parent = nullptr);
	~ContrastAdjustProcess();

	QString processName() override;
};

#endif // !_ContrastAdjustProcess_H_
