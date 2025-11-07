#pragma once

#include "tprocessfactoryabstract.h"

class TFreeRotateProcessFactory  : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	TFreeRotateProcessFactory(QObject *parent = nullptr);
	~TFreeRotateProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};
