#include "tbrightthreshscaleadjustprocessfactory.h"
#include "brightthreshscaleadjustprocess.h"

TBrightThreshScaleAdjustProcessFactory::TBrightThreshScaleAdjustProcessFactory(QObject *parent)
	: TThreshScaleAdjustProcessFactoryAbstract(parent)
{
	setThreshScaleAdjustImageProcess(new BrightThreshScaleAdjustProcess(), new BrightThreshScaleAdjustProcess());
}

TBrightThreshScaleAdjustProcessFactory::~TBrightThreshScaleAdjustProcessFactory()
{}
