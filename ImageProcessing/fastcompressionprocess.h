#pragma once

#ifndef _FASTCOMPRESSIONPROCESS_H_
#define _FASTCOMPRESSIONPROCESS_H_

#include "abstractimageprocess.h"
#include <QSize>

class FastCompressionProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	int counter;

protected:
	virtual void process() override;

public:
	FastCompressionProcess(QObject* parent = nullptr);
	~FastCompressionProcess();

	virtual bool processable() override;
	virtual QString processName() override;
	virtual void resetArg() override;

	void setCounter(int counter);
	int getCounter();

	//	计算结果大小算法
	QSize compressionedSize();

	// 通过 AbstractImageProcess 继承
	virtual bool resetable() override;

signals:
	void counterChanged(int counter);
};

#endif // !_FASTCOMPRESSIONPROCESS_H_
