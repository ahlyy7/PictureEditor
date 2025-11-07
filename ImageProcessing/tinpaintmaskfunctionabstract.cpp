#include "pch.h"
#include "tinpaintmaskfunctionabstract.h"
#include <QImage>
#include <QPainter>
#include "graffitiprocess.h"
#include "qtopencvpicturesupport.h"

AbstractImageProcess* TInpaintMaskFunctionAbstract::getGraphicsItem() const
{
	return graphicsItem.get();
}

void TInpaintMaskFunctionAbstract::setGraphicsStackFilterWindow(TGraphicsStackFilterWindow* graphicsStackFilterWindow)
{
	graphicsItem->setGraphicsStackFilterWindow(graphicsStackFilterWindow);
}

TGraphicsStackFilterWindow* TInpaintMaskFunctionAbstract::getGraphicsStackFilterWindow() const
{
	return graphicsItem->getGraphicsStackFilterWindow();
}

void TInpaintMaskFunctionAbstract::setTargetImage(const cv::Mat* target)
{
	this->target = target;
}

const cv::Mat* TInpaintMaskFunctionAbstract::getTargetImage() const
{
	return target;
}

TInpaintMaskFunctionAbstract::TInpaintMaskFunctionAbstract()
	: graphicsItem(new GraffitiProcess())
	, target(nullptr)
{
}

TInpaintMaskFunctionAbstract::~TInpaintMaskFunctionAbstract()
{
}

cv::Mat TInpaintMaskFunctionAbstract::tryCreateInpaintMask()
{
	if (!target || !graphicsItem->getGraphicsStackFilterWindow())
		return {};

	auto [width, height] = target->size();

	cv::Mat mask(target->size(), CV_8UC1);
	mask.setTo(cv::Scalar(0.0, 0.0, 0.0, 0.0));

	graphicsItem->setImage(&mask);
	if (!graphicsItem->tryProcess())
		return {};

	return createInpaintMask(*target, mask);
}
