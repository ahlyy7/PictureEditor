#include "pch.h"
#include "abstractimageadjustprocess.h"

AbstractImageAdjustProcess::AbstractImageAdjustProcess(QObject *parent)
	: AbstractImageProcess(parent)
	, adjustValue(0)
{}

AbstractImageAdjustProcess::~AbstractImageAdjustProcess()
{}

bool AbstractImageAdjustProcess::processable()
{
	return adjustValue;
}

bool AbstractImageAdjustProcess::resetable()
{
	return adjustValue;
}

void AbstractImageAdjustProcess::resetArg()
{
	setAdjustValue(0);
}

void AbstractImageAdjustProcess::setAdjustValue(int adjustValue)
{
	adjustValue = std::clamp(adjustValue, -255, 255);
	if (this->adjustValue == adjustValue)
		return;

	this->adjustValue = adjustValue;
	reJudge();

	emit adjustValueChanged(adjustValue);
}

int AbstractImageAdjustProcess::getAdjustValue()
{
	return adjustValue;
}

double AbstractImageAdjustProcess::getAdjustProportion(double divisor)
{
	auto adjustValue = this->adjustValue / divisor;
	adjustValue = adjustValue >= 0.0 ?
		adjustValue + 1.0 :
		-1.0 / (adjustValue - 1.0);

	return adjustValue;
}
