#pragma once

#ifndef _TNORMALCROPPROCESSFACTORY_H_
#define _TNORMALCROPPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

class TNormalCropProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

private:
	bool connectionProcess;
	bool connectionViewWidget;

public:
	TNormalCropProcessFactory(QObject* parent = nullptr);
	~TNormalCropProcessFactory();

	// 通过 TProcessFactoryAbstract 继承
	void initializeProcess() override;
};

#endif // !_TNORMALCROPPROCESSFACTORY_H_
