#include "pch.h"
#include "abstractimageblurprocess.h"

const cv::Size AbstractImageBlurProcess::initializeKsize(5, 5);

AbstractImageBlurProcess::AbstractImageBlurProcess(QObject *parent)
	: AbstractImageProcess(parent)
	, ksize(initializeKsize)
{}

AbstractImageBlurProcess::~AbstractImageBlurProcess()
{}

bool AbstractImageBlurProcess::processable()
{
	auto [width, height] = ksize;

	return width > 1 && height > 1 && width & 1 && height & 1;
}

bool AbstractImageBlurProcess::resetable()
{
	return ksize != initializeKsize;
}

void AbstractImageBlurProcess::resetArg()
{
	setKsize(initializeKsize);
}

void AbstractImageBlurProcess::setKsize(cv::Size ksize)
{
	if (this->ksize == ksize)
		return;

	this->ksize = ksize;
	reJudge();

	emit ksizeChanged(ksize);
}

cv::Size AbstractImageBlurProcess::getKsize()
{
	return ksize;
}
