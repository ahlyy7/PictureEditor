#pragma once

#ifndef _BINARIZATIONPROCESS_H_
#define _BINARIZATIONPROCESS_H_

#include "abstractimageprocess.h"
#include <opencv2/opencv.hpp>

class BinarizationProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	int threshold;
	cv::ThresholdTypes thresholdTypes;

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

public:
	static const uint8_t initializeThreshold;
	static const cv::ThresholdTypes initializethresholdTypes;

	BinarizationProcess(QObject* parent = nullptr);
	~BinarizationProcess();

	bool processable() override;
	bool resetable() override;
	QString processName() override;
	void resetArg() override;

	void setThreshold(int threshold);
	int getThreshold();

	void setThresholdTypes(cv::ThresholdTypes thresholdTypes);
	cv::ThresholdTypes getThresholdTypes();

signals:
	void thresholdChanged(int threshold);
	void thresholdTypesChanged(cv::ThresholdTypes thresholdTypes);
};

#endif // !_BINARIZATIONPROCESS_H_
