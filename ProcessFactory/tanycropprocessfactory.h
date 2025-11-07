#pragma once

#ifndef _TANYCROPPROCESSFACTORY_H_
#define _TANYCROPPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TAnyCropProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

private:
	bool connection;

public:
	TAnyCropProcessFactory(QObject* parent = nullptr);
	~TAnyCropProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TANYCROPPROCESSFACTORY_H_
