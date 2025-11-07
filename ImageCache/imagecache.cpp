// ImageCache.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"
#include "imagecache.h"
#include <opencv2/opencv.hpp>
#include "qtopencvpicturesupport.h"

void ImageCache::setCurrentIndex(size_t index)
{
	if (currentIndex == index)
		return;

	auto oldCurrentIndex = currentIndex;
	currentIndex = index;

	auto size = matStack.size();

	if (index == 0)
		emit emptyed(true);
	else if (oldCurrentIndex == 0)
		emit emptyed(false);

	if (index == 1)
		emit arrivedBack(true);
	else if (oldCurrentIndex == 1)
		emit arrivedBack(false);

	if (index == size)
		emit arrivedFront(true);
	else if (oldCurrentIndex == size)
		emit arrivedFront(false);

	if (index)
		emit currentImageChanged();
}

ImageCache::ImageCache(QObject* parent)
	: QObject(parent)
	, currentIndex(0ULL)
{
}

ImageCache::ImageCache(const cv::Mat& mat)
	: ImageCache()
{
	pushImage(mat);
}

ImageCache::ImageCache(const QImage& image)
	: ImageCache()
{
	pushImage(image);
}

ImageCache::~ImageCache()
{
}

void ImageCache::clear()
{
	setCurrentIndex(0ULL);
	matStack.clear();
}

void ImageCache::pushImage(const cv::Mat& mat)
{
	std::unique_ptr<cv::Mat> ptr(new cv::Mat());
	mat.copyTo(*ptr);

	matStack.resize(currentIndex + 1);
	matStack.back() = std::move(ptr);

	setCurrentIndex(currentIndex + 1);
}

void ImageCache::pushImage(cv::Mat&& mat)
{
	std::unique_ptr<cv::Mat> ptr(new cv::Mat());
	*ptr = mat;

	matStack.resize(currentIndex + 1);
	matStack.back() = std::move(ptr);

	setCurrentIndex(currentIndex + 1);
}

void ImageCache::pushImage(const QImage& image)
{
	pushImage(toOpenCVPicture(image));
}

void ImageCache::fallbackImage()
{
	setCurrentIndex(currentIndex - 1);
}

void ImageCache::forwardImage()
{
	setCurrentIndex(currentIndex + 1);
}

cv::Mat ImageCache::getCurrentImage()
{
	cv::Mat result;
	matStack[currentIndex - 1]->copyTo(result);

	return result;
}
