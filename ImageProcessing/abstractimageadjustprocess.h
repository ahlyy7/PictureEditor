#pragma once

#ifndef _ABSTRACTIMAGEADJUSTPROCESS_H_
#define _ABSTRACTIMAGEADJUSTPROCESS_H_

#include "abstractimageprocess.h"

class AbstractImageAdjustProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	int adjustValue;

public:
	AbstractImageAdjustProcess(QObject* parent = nullptr);
	virtual ~AbstractImageAdjustProcess() override = 0;

	bool processable() override;
	bool resetable() override;
	void resetArg() override;

	void setAdjustValue(int adjustValue);
	int getAdjustValue();

	double getAdjustProportion(double divisor);

signals:
	void adjustValueChanged(int adjustValue);
};

#endif // !_ABSTRACTIMAGEADJUSTPROCESS_H_
