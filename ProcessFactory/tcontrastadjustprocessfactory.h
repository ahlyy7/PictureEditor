#pragma once

#ifndef _TCONTRASTADJUSTPROCESSFACTORY_H_
#define _TCONTRASTADJUSTPROCESSFACTORY_H_

#include "tadjustprocessfactoryabstract.h"

class TContrastAdjustProcessFactory : public TAdjustProcessFactoryAbstract
{
	Q_OBJECT

public:
	TContrastAdjustProcessFactory(QObject* parent = nullptr);
	~TContrastAdjustProcessFactory();
};

#endif // !_TCONTRASTADJUSTPROCESSFACTORY_H_
