#pragma once

#ifndef _INPAINTPROCESS_H_
#define _INPAINTPROCESS_H_

#include "abstractimageprocess.h"
#include <memory>

class TInpaintMaskFunctionAbstract;

class InpaintProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	std::unique_ptr<TInpaintMaskFunctionAbstract> graphicsItem;
	int inpaintFlag;

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

public:
	static const int initializeInpaintFlag;

	static double calculateInpaintRadius(const cv::Mat& image, const cv::Mat& mask);

	InpaintProcess(QObject* parent = nullptr);
	~InpaintProcess();

	void setInpaintMaskFunction(TInpaintMaskFunctionAbstract* graphicsItem);
	TInpaintMaskFunctionAbstract* getInpaintMaskFunction() const;

	void setInpaintFlag(int inpaintFlag);
	int getInpaintFlag() const;

	bool processable() override;
	bool resetable() override;
	QString processName() override;
	void resetArg() override;

signals:
	void inpaintMaskFunctionChanged(TInpaintMaskFunctionAbstract* graphicsItem);
	void inpaintFlagChanged(int inpaintFlag);
};

#endif // !_INPAINTPROCESS_H_
