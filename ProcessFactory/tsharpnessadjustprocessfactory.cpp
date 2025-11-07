#include "tsharpnessadjustprocessfactory.h"
#include "sharpnessadjustprocess.h"

TSharpnessAdjustProcessFactory::TSharpnessAdjustProcessFactory(QObject *parent)
	: TAdjustProcessFactoryAbstract(parent)
{
	setAdjustImageProcess(new SharpnessAdjustProcess(), new SharpnessAdjustProcess());
}

TSharpnessAdjustProcessFactory::~TSharpnessAdjustProcessFactory()
{}
