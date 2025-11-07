#include "pch.h"
#include "tdarkthreshscaleadjustprocessfactory.h"
#include "darkthreshscaleadjustprocess.h"

TDarkThreshScaleAdjustProcessFactory::TDarkThreshScaleAdjustProcessFactory(QObject *parent)
	: TThreshScaleAdjustProcessFactoryAbstract(parent)
{
	setThreshScaleAdjustImageProcess(new DarkThreshScaleAdjustProcess(), new DarkThreshScaleAdjustProcess());
}

TDarkThreshScaleAdjustProcessFactory::~TDarkThreshScaleAdjustProcessFactory()
{}
