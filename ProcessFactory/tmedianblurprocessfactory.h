#pragma once

#ifndef _TMEDIANBLURPROCESSFACTORY_H_
#define _TMEDIANBLURPROCESSFACTORY_H_

#include "tblurprocessfactoryabstract.h"

class TMedianBlurProcessFactory : public TBlurProcessFactoryAbstract
{
	Q_OBJECT

public:
	TMedianBlurProcessFactory(QObject* parent = nullptr);
	~TMedianBlurProcessFactory();
};

#endif // !_TMEDIANBLURPROCESSFACTORY_H_
