#pragma once

#ifndef _EQUALIZEHISTIMAGEPROCESS_H_
#define _EQUALIZEHISTIMAGEPROCESS_H_

#include "abstractimageprocess.h"

class EqualizeHistImageProcess : public AbstractImageProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

public:
	EqualizeHistImageProcess(QObject* parent = nullptr);
	~EqualizeHistImageProcess();

	bool processable() override;
	bool resetable() override;
	QString processName() override;
	void resetArg() override;
};

#endif // !_EqualizeHistImageProcess_H_
