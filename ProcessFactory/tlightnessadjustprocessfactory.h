#pragma once

#ifndef _TLIGHTNESSADJUSTPROCESSFACTORY_H_
#define _TLIGHTNESSADJUSTPROCESSFACTORY_H_

#include "tadjustprocessfactoryabstract.h"

class TLightnessAdjustProcessFactory : public TAdjustProcessFactoryAbstract
{
	Q_OBJECT

public:
	TLightnessAdjustProcessFactory(QObject* parent = nullptr);
	~TLightnessAdjustProcessFactory();
};

#endif // !_TLIGHTNESSADJUSTPROCESSFACTORY_H_
