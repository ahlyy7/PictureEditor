#pragma once

#ifndef _TINPAINTMASKFUNCTION_H_
#define _TINPAINTMASKFUNCTION_H_

#include "tinpaintmaskfunctionabstract.h"

class TGrabCutInpaintMaskFunction : public TInpaintMaskFunctionAbstract
{
protected:
	// 通过 TInpaintMaskFunctionAbstract 继承
	cv::Mat createInpaintMask(const cv::Mat& target, const cv::Mat& mask) override;

public:
	static cv::Mat expandMaskWithGrabCut(const cv::Mat& target, const cv::Mat& mask);
};

#endif // !_TINPAINTMASKFUNCTION_H_
