#pragma once

#ifndef _TFREECOMPRESSIONPROCESSFACTORY_H_
#define _TFREECOMPRESSIONPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TFreeCompressionProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

private:
	bool connectable;

public:
	TFreeCompressionProcessFactory(QObject* parent = nullptr);
	~TFreeCompressionProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	virtual void initializeProcess() override;
};

#endif // !_TFREECOMPRESSIONPROCESSFACTORY_H_
