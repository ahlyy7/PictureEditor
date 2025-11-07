#pragma once

#ifndef _TFLIPPROCESSFACTORY_H_
#define _TFLIPPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TFlipProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TFlipProcessFactory(QObject* parent = nullptr);
	~TFlipProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TFLIPPROCESSFACTORY_H_
