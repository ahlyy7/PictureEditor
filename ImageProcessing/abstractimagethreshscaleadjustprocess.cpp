#include "pch.h"
#include "abstractimagethreshscaleadjustprocess.h"

AbstractImageThreshScaleAdjustProcess::AbstractImageThreshScaleAdjustProcess(QObject *parent)
	: AbstractImageAdjustProcess(parent)
	, thresh(127)
{}

AbstractImageThreshScaleAdjustProcess::~AbstractImageThreshScaleAdjustProcess()
{}

void AbstractImageThreshScaleAdjustProcess::setThresh(int thresh)
{
	thresh = std::clamp(thresh, -1, 255);

	if (this->thresh == thresh)
		return;

	this->thresh = thresh;
	reJudge();

	emit threshChanged(thresh);
}

int AbstractImageThreshScaleAdjustProcess::getThresh()
{
	return thresh;
}

bool AbstractImageThreshScaleAdjustProcess::resetable()
{
	return AbstractImageAdjustProcess::resetable() || thresh != 127;
}

void AbstractImageThreshScaleAdjustProcess::resetArg()
{
	AbstractImageAdjustProcess::resetArg();
	setThresh(127);
}
