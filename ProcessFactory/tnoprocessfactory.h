#pragma once

#ifndef _TNOPROCESSFACTORY_H_
#define _TNOPROCESSFACTORY_H_

#include "tprocessfactoryabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TNoProcessFactoryClass; };
QT_END_NAMESPACE

class TNoProcessFactory : public TProcessFactoryAbstract
{
	Q_OBJECT

public:
	virtual void initializeProcess() override;

	TNoProcessFactory(QWidget* parent = nullptr);
	~TNoProcessFactory();
};

#endif // !_TNOPROCESSFACTORY_H_
