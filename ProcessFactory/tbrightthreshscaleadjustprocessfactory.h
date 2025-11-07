#pragma once

#ifndef _TBRIGHTTHRESHSCALEADJUSTPROCESSFACTORY_H_
#define _TBRIGHTTHRESHSCALEADJUSTPROCESSFACTORY_H_

#include "tthreshscaleadjustprocessfactoryabstract.h"

class TBrightThreshScaleAdjustProcessFactory : public TThreshScaleAdjustProcessFactoryAbstract
{
	Q_OBJECT

public:
	TBrightThreshScaleAdjustProcessFactory(QObject* parent = nullptr);
	~TBrightThreshScaleAdjustProcessFactory();
};

#endif // !_TBRIGHTTHRESHSCALEADJUSTPROCESSFACTORY_H_
