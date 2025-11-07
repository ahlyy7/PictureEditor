#pragma once

#ifndef _TSIMPEBLURPROCESSFACTORY_H_
#define _TSIMPEBLURPROCESSFACTORY_H_

#include "tblurprocessfactoryabstract.h"

class TSimpeBlurProcessFactory : public TBlurProcessFactoryAbstract
{
	Q_OBJECT

public:
	TSimpeBlurProcessFactory(QObject* parent = nullptr);
	~TSimpeBlurProcessFactory();
};

#endif // !_TSIMPEBLURPROCESSFACTORY_H_
