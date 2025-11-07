#pragma once

#ifndef _GRAYSCALEPROCESS_H_
#define _GRAYSCALEPROCESS_H_

#include "abstractimageprocess.h"

class GrayscaleProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	int channels;

protected:
	virtual void process() override;
	virtual void resetArgAfterImageChanged() override;

public:
	virtual bool processable() override;

	// 通过 AbstractImageProcess 继承
	virtual bool resetable() override;

	GrayscaleProcess(QObject* parent = nullptr);
	virtual ~GrayscaleProcess() override;

	// 通过 AbstractImageProcess 继承
	QString processName() override;

	// 通过 AbstractImageProcess 继承
	virtual void resetArg() override;

signals:
	void channelsChanged(int channels);
};

#endif // !_GRAYSCALEPROCESS_H_
