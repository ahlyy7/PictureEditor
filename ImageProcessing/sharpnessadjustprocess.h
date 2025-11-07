#pragma once

#ifndef _SHARPNESSADJUSTPROCESS_H_
#define _SHARPNESSADJUSTPROCESS_H_

#include "abstractimageadjustprocess.h"

class SharpnessAdjustProcess : public AbstractImageAdjustProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageAdjustProcess 继承
	void process() override;

public:
	static void adjustSharpness(cv::Mat* input, double intensity);

	SharpnessAdjustProcess(QObject* parent = nullptr);
	~SharpnessAdjustProcess();

	QString processName() override;
};

#endif // !_SHARPNESSADJUSTPROCESS_H_
