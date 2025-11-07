#include "pch.h"
#include "tmedianblurprocessfactory.h"
#include "medianblurprocess.h"

TMedianBlurProcessFactory::TMedianBlurProcessFactory(QObject *parent)
	: TBlurProcessFactoryAbstract(parent)
{
	setBlurImageProcess(new MedianBlurProcess(), new MedianBlurProcess());
}

TMedianBlurProcessFactory::~TMedianBlurProcessFactory()
{}
