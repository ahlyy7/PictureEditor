#include "pch.h"
#include "tlightnessadjustprocessfactory.h"
#include "lightnessadjustprocess.h"

TLightnessAdjustProcessFactory::TLightnessAdjustProcessFactory(QObject *parent)
	: TAdjustProcessFactoryAbstract(parent)
{
	setAdjustImageProcess(new LightnessAdjustProcess(), new LightnessAdjustProcess());
}

TLightnessAdjustProcessFactory::~TLightnessAdjustProcessFactory()
{}
