#pragma once

#ifndef _TSHARPNESSADJUSTPROCESSFACTORY_H_
#define _TSHARPNESSADJUSTPROCESSFACTORY_H_

#include "tadjustprocessfactoryabstract.h"

class TSharpnessAdjustProcessFactory : public TAdjustProcessFactoryAbstract
{
	Q_OBJECT

public:
	TSharpnessAdjustProcessFactory(QObject* parent = nullptr);
	~TSharpnessAdjustProcessFactory();
};

#endif // !_TSHARPNESSADJUSTPROCESSFACTORY_H_
