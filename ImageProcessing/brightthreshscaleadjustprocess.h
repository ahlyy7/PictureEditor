#pragma once

#ifndef _BRIGHTTHRESHSCALEADJUSTPROCESS_H_
#define _BRIGHTTHRESHSCALEADJUSTPROCESS_H_

#include "abstractimagethreshscaleadjustprocess.h"

class BrightThreshScaleAdjustProcess : public AbstractImageThreshScaleAdjustProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageThreshScaleAdjustProcess 继承
	void process() override;

public:
	static void adjustImageDynamic(cv::Mat* img, int high_thresh, double bright_scale);

	BrightThreshScaleAdjustProcess(QObject* parent = nullptr);
	~BrightThreshScaleAdjustProcess();

	QString processName() override;
};

#endif // !_BRIGHTTHRESHSCALEADJUSTPROCESS_H_
