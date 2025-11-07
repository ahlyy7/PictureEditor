#pragma once

#ifndef _TINPAINTMASKFUNCTIONABSTRACT_H_
#define _TINPAINTMASKFUNCTIONABSTRACT_H_

#include <memory>
#include <opencv2/opencv.hpp>

class AbstractImageProcess;
class GraffitiProcess;
class TGraphicsStackFilterWindow;
namespace cv
{
	class Mat;
};

class TInpaintMaskFunctionAbstract
{
private:
	std::unique_ptr<GraffitiProcess> graphicsItem;
	const cv::Mat* target;

protected:
	virtual cv::Mat createInpaintMask(const cv::Mat& target, const cv::Mat& mask) = 0;

public:
	AbstractImageProcess* getGraphicsItem() const;

	void setGraphicsStackFilterWindow(TGraphicsStackFilterWindow* graphicsStackFilterWindow);
	TGraphicsStackFilterWindow* getGraphicsStackFilterWindow() const;

	void setTargetImage(const cv::Mat* target);
	const cv::Mat* getTargetImage() const;

	TInpaintMaskFunctionAbstract();
	virtual ~TInpaintMaskFunctionAbstract() = 0;

	cv::Mat tryCreateInpaintMask();
};

#endif // !_TINPAINTMASKFUNCTIONABSTRACT_H_