#pragma once

#ifndef _TGRAFFITIPROCESSFACTORY_H_
#define _TGRAFFITIPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TGraffitiProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TGraffitiProcessFactory(QObject* parent = nullptr);
	~TGraffitiProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TGRAFFITIPROCESSFACTORY_H_
