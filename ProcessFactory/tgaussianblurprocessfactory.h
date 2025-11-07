#pragma once

#ifndef _TGAUSSIANBLURPROCESSFACTORY_H_
#define _TGAUSSIANBLURPROCESSFACTORY_H_

#include "tblurprocessfactoryabstract.h"

class GaussianBlurProcess;

class TGaussianBlurProcessFactory : public TBlurProcessFactoryAbstract
{
	Q_OBJECT

private:
	GaussianBlurProcess* gaussianBlurProcess;
	GaussianBlurProcess* gaussianBlurProcessCopy;

public:
	TGaussianBlurProcessFactory(QObject* parent = nullptr);
	~TGaussianBlurProcessFactory();

	void initializeProcess() override;
};

#endif // !_TGAUSSIANBLURPROCESSFACTORY_H_
