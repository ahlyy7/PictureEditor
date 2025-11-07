#include "pch.h"
#include "tnormalinpaintmaskfunction.h"

cv::Mat TNormalInpaintMaskFunction::createInpaintMask(const cv::Mat& target, const cv::Mat& mask)
{
    return mask;
}
