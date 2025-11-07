#pragma once

#ifndef _TSATURATIONADJUSTPROCESSFACTORY_H_
#define _TSATURATIONADJUSTPROCESSFACTORY_H_

#include "tadjustprocessfactoryabstract.h"

class TSaturationAdjustProcessFactory : public TAdjustProcessFactoryAbstract
{
	Q_OBJECT

public:
	TSaturationAdjustProcessFactory(QObject* parent = nullptr);
	~TSaturationAdjustProcessFactory();

	void initializeProcess() override;
};

#endif // !_TSATURATIONADJUSTPROCESSFACTORY_H_
