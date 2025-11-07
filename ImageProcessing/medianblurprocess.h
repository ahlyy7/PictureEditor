#pragma once

#ifndef _MEDIANBLUR_H_
#define _MEDIANBLUR_H_

#include "abstractimageblurprocess.h"

class MedianBlurProcess : public AbstractImageBlurProcess
{
	Q_OBJECT

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

public:
	MedianBlurProcess(QObject* parent = nullptr);
	~MedianBlurProcess();

	QString processName() override;
};

#endif // !_MEDIANBLUR_H_
