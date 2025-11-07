#pragma once

#ifndef _SATURATIONADJUSTPROCESS_H_
#define _SATURATIONADJUSTPROCESS_H_

#include "abstractimageadjustprocess.h"

class SaturationAdjustProcess : public AbstractImageAdjustProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageAdjustProcess 继承
	void process() override;

public:
	static void adjustSaturation(cv::Mat* src, double factor);

	SaturationAdjustProcess(QObject* parent = nullptr);
	~SaturationAdjustProcess();

	bool processable() override;
	QString processName() override;
};

#endif // !_SATURATIONADJUSTPROCESS_H_
