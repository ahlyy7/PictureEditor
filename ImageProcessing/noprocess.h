#pragma once

#ifndef _NOPROCESS_H_
#define _NOPROCESS_H_

#include "abstractimageprocess.h"

class NoProcess : public AbstractImageProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageProcess 继承
	virtual void process() override;

public:
	// 通过 AbstractImageProcess 继承
	virtual bool processable() override;

	NoProcess(QObject* parent = nullptr);
	virtual ~NoProcess() override;

	// 通过 AbstractImageProcess 继承
	QString processName() override;

	// 通过 AbstractImageProcess 继承
	virtual void resetArg() override;

	// 通过 AbstractImageProcess 继承
	virtual bool resetable() override;
};

#endif // !_NOPROCESS_H_
