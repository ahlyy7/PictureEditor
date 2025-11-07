#pragma once

#ifndef _DARKTHRESHSCALEADJUSTPROCESS_H_
#define _DARKTHRESHSCALEADJUSTPROCESS_H_

#include "abstractimagethreshscaleadjustprocess.h"

class DarkThreshScaleAdjustProcess : public AbstractImageThreshScaleAdjustProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageThreshScaleAdjustProcess 继承
	void process() override;

public:
	static void adjustImageDynamic(cv::Mat* img, int low_thresh, double dark_scale);

	DarkThreshScaleAdjustProcess(QObject* parent = nullptr);
	~DarkThreshScaleAdjustProcess();

	QString processName() override;
};

#endif // !_DARKTHRESHSCALEADJUSTPROCESS_H_
