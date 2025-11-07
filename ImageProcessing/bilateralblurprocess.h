#pragma once

#ifndef _BILATERALBLURPROCESS_H_
#define _BILATERALBLURPROCESS_H_

#include "abstractimageblurprocess.h"

class BilateralBlurProcess : public AbstractImageBlurProcess
{
	Q_OBJECT

private:
	double sigmaColor;
	double sigmaSpace;

protected:
	// 通过 AbstractImageBlurProcess 继承
	void process() override;

public:
	BilateralBlurProcess(QObject* parent = nullptr);
	~BilateralBlurProcess();

	bool processable() override;
	bool resetable() override;
	void resetArg() override;

	QString processName() override;

	void setSigmaColor(double sigmaColor);
	double getSigmaColor();

	void setSigmaSpace(double sigmaSpace);
	double getSigmaSpace();

signals:
	void sigmaColorChanged(double sigmaColor);
	void sigmaSpaceChanged(double sigmaSpace);
};

#endif // !_BILATERALBLURPROCESS_H_
