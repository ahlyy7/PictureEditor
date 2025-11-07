#pragma once

#ifndef _TBINARIZATIONPROCESSFACTORY_H_
#define _TBINARIZATIONPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TBinarizationProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TBinarizationProcessFactory(QObject* parent = nullptr);
	~TBinarizationProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TBINARIZATIONPROCESSFACTORY_H_
