#pragma once

#ifndef _TTHRESHSCALEADJUSTPROCESSFACTORYABSTRACT_H_
#define _TTHRESHSCALEADJUSTPROCESSFACTORYABSTRACT_H_

#include "tadjustprocessfactoryabstract.h"

class AbstractImageThreshScaleAdjustProcess;

class TThreshScaleAdjustProcessFactoryAbstract : public TAdjustProcessFactoryAbstract
{
	Q_OBJECT

private:
	AbstractImageThreshScaleAdjustProcess* imageProcess;
	AbstractImageThreshScaleAdjustProcess* imageProcessCopy;

	using TAdjustProcessFactoryAbstract::setAdjustImageProcess;

protected:
	void setThreshScaleAdjustImageProcess(AbstractImageThreshScaleAdjustProcess* imageProcess, AbstractImageThreshScaleAdjustProcess* imageProcessCopy);

public:
	TThreshScaleAdjustProcessFactoryAbstract(QObject* parent = nullptr);
	virtual ~TThreshScaleAdjustProcessFactoryAbstract() override = 0;
	
	void initializeProcess() override;
};

#endif // !_TTHRESHSCALEADJUSTPROCESSFACTORYABSTRACT_H_
