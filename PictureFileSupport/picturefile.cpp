#include "pch.h"
#include "picturefile.h"
#include <opencv2/opencv.hpp>

struct PictureFilePrivate
{
	std::string filePath;
	cv::Mat image;
};

PictureFile::PictureFile()
	: impl(new PictureFilePrivate())
{
}

PictureFile::PictureFile(const std::string& filePath)
	: PictureFile()
{
	setFilePath(filePath);
}

PictureFile::~PictureFile()
{
	delete impl;
}

void PictureFile::setFilePath(const std::string& filePath)
{
	impl->filePath = filePath;
}

const std::string& PictureFile::filePath()
{
	return impl->filePath;
}

bool PictureFile::load()
{
    impl->image = cv::imread(impl->filePath, cv::IMREAD_UNCHANGED);
    if (impl->image.empty())
        return false;

    int channels = impl->image.channels();
    //if (channels == 4)
    //    cv::cvtColor(impl->image, impl->image, cv::COLOR_BGRA2BGR); // ÒÆ³ýAlphaÍ¨µÀ

	return true;
}

bool PictureFile::save()
{
	return cv::imwrite(impl->filePath, impl->image);
}

bool PictureFile::save(const cv::Mat& image)
{
	return cv::imwrite(impl->filePath, image);
}

const cv::Mat& PictureFile::getPicture()
{
	return impl->image;
}

void PictureFile::setPicture(const cv::Mat& image)
{
	image.copyTo(impl->image);
}
