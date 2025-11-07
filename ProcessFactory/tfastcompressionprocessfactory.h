#pragma once

#ifndef _TFASTCOMPRESSIONPROCESSFACTORY_H_
#define _TFASTCOMPRESSIONPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TFastCompressionProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TFastCompressionProcessFactory(QObject* parent = nullptr);
	virtual ~TFastCompressionProcessFactory() override;

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TFASTCOMPRESSIONPROCESSFACTORY_H_
