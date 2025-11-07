#pragma once

#ifndef _TBLURPROCESSFACTORYABSTRACT_H_
#define _TBLURPROCESSFACTORYABSTRACT_H_

#include "tprocessfactoryabstract.h"

class AbstractImageBlurProcess;

class TBlurProcessFactoryAbstract : public TProcessFactoryAbstract
{
	Q_OBJECT

private:
	AbstractImageBlurProcess* imageProcess;
	AbstractImageBlurProcess* imageProcessCopy;

protected:
	void setBlurImageProcess(AbstractImageBlurProcess* imageProcess, AbstractImageBlurProcess* imageProcessCopy);

public:
	TBlurProcessFactoryAbstract(QObject* parent = nullptr);
	~TBlurProcessFactoryAbstract() = 0;

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TBLURPROCESSFACTORYABSTRACT_H_
