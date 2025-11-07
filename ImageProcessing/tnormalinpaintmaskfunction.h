#pragma once

#ifndef _TNORMALINPAINTMASKFUNCTION_H_
#define _TNORMALINPAINTMASKFUNCTION_H_

#include "tinpaintmaskfunctionabstract.h"

class TNormalInpaintMaskFunction : public TInpaintMaskFunctionAbstract
{
protected:
	// 通过 TInpaintMaskFunctionAbstract 继承
	cv::Mat createInpaintMask(const cv::Mat& target, const cv::Mat& mask) override;
};

#endif // !_TNORMALINPAINTMASKFUNCTION_H_
