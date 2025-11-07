#pragma once

#ifndef _SIMPLEROTATEPROCESS_H_
#define _SIMPLEROTATEPROCESS_H_

#include "abstractimageprocess.h"
#include <opencv2/opencv.hpp>

class SimpleRotateProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	cv::RotateFlags rotateCode;

protected:
	// 通过 AbstractImageProcess 继承
	virtual void process() override;

public:
	static const cv::RotateFlags initializeRotateCode;

	SimpleRotateProcess(QObject* parent = nullptr);
	~SimpleRotateProcess();

	virtual bool processable() override;
	virtual bool resetable() override;
	virtual QString processName() override;
	virtual void resetArg() override;

	void setRotateCode(cv::RotateFlags rotateCode);
	cv::RotateFlags getRotateCode();

signals:
	void rotateCodeChanged(cv::RotateFlags rotateCode);
};

#endif // !_SIMPLEROTATEPROCESS_H_
