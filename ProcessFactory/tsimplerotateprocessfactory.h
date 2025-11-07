#pragma once

#ifndef _TSIMPLEROTATEPROCESSFACTORY_H_
#define _TSIMPLEROTATEPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TSimpleRotateProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TSimpleRotateProcessFactory(QObject* parent = nullptr);
	~TSimpleRotateProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TSIMPLEROTATEPROCESSFACTORY_H_
