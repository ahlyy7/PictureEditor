#pragma once

#ifndef _FLIPPROCESS_H_
#define _FLIPPROCESS_H_

#include "abstractimageprocess.h"

class FlipProcess : public AbstractImageProcess
{
	Q_OBJECT

public:
	enum FlieCode
	{
		NoFlip = -2,
		BothAxes,
		XAxis,
		YAxis
	};

private:
	FlieCode flipCode;

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

public:
	FlipProcess(QObject* parent = nullptr);
	~FlipProcess();

	bool processable() override;
	bool resetable() override;
	QString processName() override;
	void resetArg() override;

	void setFlipCode(FlieCode flipCode);
	FlieCode getFlipCode();

signals:
	void flipCodeChanged(FlieCode flipCode);
};

#endif // !_FLIPPROCESS_H_
