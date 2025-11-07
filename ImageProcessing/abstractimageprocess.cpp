// ImageProcessing.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"
#include "abstractimageprocess.h"
#include <opencv2/opencv.hpp>

void AbstractImageProcess::reJudge()
{
	bool canProcess = target && processable();

	if (this->canProcess != canProcess)
	{
		this->canProcess = canProcess;
		emit processableChanged(canProcess);
	}

	bool canReset = target && resetable();

	if (this->canReset != canReset)
	{
		this->canReset = canReset;
		emit resetableChanged(canReset);
	}

	emit reJudged();
}

void AbstractImageProcess::resetArgAfterImageChanged()
{
}

cv::Mat* AbstractImageProcess::getImage()
{
	return target;
}

void AbstractImageProcess::setImage(cv::Mat* target)
{
	this->target = target;

	if (target)
		resetArgAfterImageChanged();
	reJudge();

	emit imageChanged(target);
}

bool AbstractImageProcess::tryProcess()
{
	if (!this->canProcess)
		return false;

	process();

	resetArgAfterImageChanged();
	reJudge();

	emit processed();
	emit imageChanged(target);
	return true;
}

AbstractImageProcess::AbstractImageProcess(QObject* parent, cv::Mat* target)
	: QObject(parent)
	, canProcess(false)
	, canReset(false)
	, target(target)
{
	//setImage(target);
}

AbstractImageProcess::~AbstractImageProcess()
{
}
