#pragma once

#ifndef _SIMPLEBLURPROCESS_H_
#define _SIMPLEBLURPROCESS_H_

#include "abstractimageblurprocess.h"

class SimpleBlurProcess : public AbstractImageBlurProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

public:
	SimpleBlurProcess(QObject* parent = nullptr);
	~SimpleBlurProcess();

	QString processName() override;
};

#endif // !_SIMPLEBLURPROCESS_H_
