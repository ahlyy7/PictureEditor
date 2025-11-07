#pragma once

#ifndef _IMAGECACHE_H_
#define _IMAGECACHE_H_

#include <QObject>
#include <memory>
#include <vector>

namespace cv
{
	class Mat;
};

class QImage;

class ImageCache : public QObject
{
	Q_OBJECT

private:
	std::vector<std::unique_ptr<cv::Mat>> matStack;
	size_t currentIndex;

	void setCurrentIndex(size_t index);

public:
	ImageCache(QObject* parent = nullptr);
	ImageCache(const cv::Mat& mat);
	ImageCache(const QImage& image);
	~ImageCache();

	void clear();

	void pushImage(const cv::Mat& mat);
	void pushImage(cv::Mat&& mat);
	void pushImage(const QImage& image);

	void fallbackImage();

	void forwardImage();

	cv::Mat getCurrentImage();

signals:
	void emptyed(bool empty);
	void currentImageChanged();

	void arrivedFront(bool arrived);
	void arrivedBack(bool arrived);
};

#endif // !_IMAGECACHE_H_
