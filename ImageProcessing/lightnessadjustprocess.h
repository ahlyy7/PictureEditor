#pragma once

#ifndef _LIGHTNESSADJUSTPROCESS_H_
#define _LIGHTNESSADJUSTPROCESS_H_

#include "abstractimageadjustprocess.h"

class LightnessAdjustProcess : public AbstractImageAdjustProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageAdjustProcess 继承
	void process() override;

public:
	static void adjustBrightness(cv::Mat* img, int delta);

	LightnessAdjustProcess(QObject* parent = nullptr);
	~LightnessAdjustProcess();

	QString processName() override;
};

#endif // !_LIGHTNESSADJUSTPROCESS_H_
