#pragma once

#ifndef _ABSTRACTIMAGETHRESHSCALEADJUSTPROCESS_H_
#define _ABSTRACTIMAGETHRESHSCALEADJUSTPROCESS_H_

#include "abstractimageadjustprocess.h"

class AbstractImageThreshScaleAdjustProcess : public AbstractImageAdjustProcess
{
	Q_OBJECT

private:
	int thresh;

public:
	AbstractImageThreshScaleAdjustProcess(QObject* parent = nullptr);
	~AbstractImageThreshScaleAdjustProcess() = 0;

	void setThresh(int thresh);
	int getThresh();

	bool resetable() override;
	void resetArg() override;

signals:
	void threshChanged(int thresh);
};

#endif // !_ABSTRACTIMAGETHRESHSCALEADJUSTPROCESS_H_
