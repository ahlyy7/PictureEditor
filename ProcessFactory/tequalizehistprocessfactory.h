#pragma once

#ifndef _TEQUALIZEHISTPROCESSFACTORY_H_
#define _TEQUALIZEHISTPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TEqualizeHistProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TEqualizeHistProcessFactory(QObject* parent = nullptr);
	~TEqualizeHistProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TEQUALIZEHISTPROCESSFACTORY_H_
