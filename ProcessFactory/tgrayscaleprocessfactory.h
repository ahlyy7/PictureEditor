#pragma once

#ifndef _TGRAYSCALEPROCESSFACTORY_H_
#define _TGRAYSCALEPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TGrayscaleProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TGrayscaleProcessFactory(QObject* parent = nullptr);
	virtual ~TGrayscaleProcessFactory() override;

	void initializeProcess() override;
};

#endif // !_TGRAYSCALEPROCESSFACTORY_H_
