#pragma once

#ifndef _TBILATERALBLURPROCESSFACTORY_H_
#define _TBILATERALBLURPROCESSFACTORY_H_

#include "tblurprocessfactoryabstract.h"

class BilateralBlurProcess;

class TBilateralBlurProcessFactory : public TBlurProcessFactoryAbstract
{
	Q_OBJECT

private:
	BilateralBlurProcess* bilateralBlurProcess;

public:
	TBilateralBlurProcessFactory(QObject* parent = nullptr);
	~TBilateralBlurProcessFactory();

	void initializeProcess() override;
};

#endif // !_TBILATERALBLURPROCESSFACTORY_H_
