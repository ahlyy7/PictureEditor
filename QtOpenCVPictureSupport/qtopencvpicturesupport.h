#pragma once

#ifndef _QTOPENCVPICTURESUPPORT_H_
#define _QTOPENCVPICTURESUPPORT_H_

#define QTOPENCVPICTURESUPPORT_VERSION 2

#include <opencv2/opencv.hpp>
#include <QPixmap>

cv::Mat toOpenCVPicture(const QImage& image);
QImage toQtPicture(const cv::Mat& mat);

#endif // !_QTOPENCVPICTURESUPPORT_H_
