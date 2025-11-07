#pragma once

#ifndef _TINPAINTPROCESSFACTORY_H_
#define _TINPAINTPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TInpaintProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TInpaintProcessFactory(QObject* parent = nullptr);
	~TInpaintProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TINPAINTPROCESSFACTORY_H_
