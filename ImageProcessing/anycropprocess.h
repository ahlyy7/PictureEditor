#pragma once

#ifndef _ANGCROPPROCESS_H_
#define _ANGCROPPROCESS_H_

#include "abstractimageprocess.h"
#include <array>
#include <opencv2/opencv.hpp>

//namespace cv
//{
//	template<typename T>
//	class Point_;
//
//	typedef Point_<float> Point2f;
//
//	template<typename _Tp>
//	class Size_;
//	typedef Size_<int> Size2i;
//	typedef Size2i Size;
//};

class AnyCropProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	std::array<cv::Point2f, 4> targetPoints;
	std::array<cv::Point2f, 4> imagePoints;

	cv::Size targetSize;
	cv::Size imageSize;

	cv::InterpolationFlags interpolationFlags;

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

	virtual void resetArgAfterImageChanged();

public:
	static const cv::InterpolationFlags initializeInterpolationFlags;

	AnyCropProcess(QObject* parent = nullptr);
	~AnyCropProcess();

	bool processable() override;
	bool resetable() override;
	QString processName() override;
	void resetArg() override;

	void setTargetPoints(const std::array<cv::Point2f, 4>& targetPoints);
	void setTargetPoints(const cv::Point2f targetPoints[]);
	void setTargetPoint(cv::Point2f targetPoint, int index);
	const std::array<cv::Point2f, 4>& getTargetPoints();

	void setSize(cv::Size size);
	cv::Size getSize();

	void setInterpolationFlags(cv::InterpolationFlags interpolationFlags);
	cv::InterpolationFlags getInterpolationFlags();

signals:
	void targetPointsChanged(const std::array<cv::Point2f, 4>& targetPoints);
	void targetSizeChanged(cv::Size size);
	void interpolationFlagsChanged(cv::InterpolationFlags interpolationFlags);
};

#endif // !_ANGCROPPROCESS_H_
