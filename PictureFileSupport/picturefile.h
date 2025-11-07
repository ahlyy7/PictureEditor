#pragma once

#ifndef _PICTUREFILE_H_
#define _PICTUREFILE_H_

#include <string>

struct PictureFilePrivate;

namespace cv
{
	class Mat;
};

class PictureFile
{
	//std::unique_ptr<PictureFilePrivate> impl;
	PictureFilePrivate* const impl;

public:
	PictureFile();
	PictureFile(const std::string& filePath);
	~PictureFile();

	void setFilePath(const std::string& filePath);
	const std::string& filePath();

	bool load();
	bool save();
	bool save(const cv::Mat& image);

	const cv::Mat& getPicture();
	void setPicture(const cv::Mat& image);
};

#endif // !_PICTUREFILE_H_
