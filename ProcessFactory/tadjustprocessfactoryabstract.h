#pragma once

#ifndef _TAdjustProcessFactoryAbstract_H_
#define _TAdjustProcessFactoryAbstract_H_

#include "tprocessfactoryabstract.h"

class AbstractImageAdjustProcess;

class TAdjustProcessFactoryAbstract : public TProcessFactoryAbstract
{
	Q_OBJECT

private:
	AbstractImageAdjustProcess* imageProcess;
	AbstractImageAdjustProcess* imageProcessCopy;

protected:
	void setAdjustImageProcess(AbstractImageAdjustProcess* imageProcess, AbstractImageAdjustProcess* imageProcessCopy);

public:
	TAdjustProcessFactoryAbstract(QObject* parent = nullptr);
	virtual ~TAdjustProcessFactoryAbstract() override = 0;

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TAdjustProcessFactoryAbstract_H_
