#pragma once

#ifndef _GAUSSIANBLURPROCESS_H_
#define _GAUSSIANBLURPROCESS_H_

#include "abstractimageblurprocess.h"

class GaussianBlurProcess : public AbstractImageBlurProcess
{
	Q_OBJECT

private:
	double sigma;

protected:
	// 通过 AbstractImageBlurProcess 继承
	void process() override;

public:
	GaussianBlurProcess(QObject* parent = nullptr);
	~GaussianBlurProcess();

	bool processable() override;
	bool resetable() override;
	void resetArg() override;

	QString processName() override;

	void setSigma(double sigma);
	double getSigma();

signals:
	void sigmaChanged(double sigma);
};

#endif // !_GAUSSIANBLURPROCESS_H_
