#pragma once

#ifndef _TDARKTHRESHSCALEADJUSTPROCESSFACTORY_H_
#define _TDARKTHRESHSCALEADJUSTPROCESSFACTORY_H_

#include "tthreshscaleadjustprocessfactoryabstract.h"

class TDarkThreshScaleAdjustProcessFactory : public TThreshScaleAdjustProcessFactoryAbstract
{
	Q_OBJECT

public:
	TDarkThreshScaleAdjustProcessFactory(QObject* parent = nullptr);
	~TDarkThreshScaleAdjustProcessFactory();
};

#endif // !_TDARKTHRESHSCALEADJUSTPROCESSFACTORY_H_
