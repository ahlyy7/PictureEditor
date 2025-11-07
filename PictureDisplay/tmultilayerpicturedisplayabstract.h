#pragma once

#ifndef _TMULTILAYERPICTUREDISPLAYABSTRACT_H_
#define _TMULTILAYERPICTUREDISPLAYABSTRACT_H_

#include "tpicturedisplayabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TMultilayerPictureDisplayAbstractClass; };
QT_END_NAMESPACE

class TMultilayerPictureDisplayAbstract : public TPictureDisplayAbstract
{
	Q_OBJECT

protected:
	TPictureDisplayAbstract* pictureDisplay;

public:
	TMultilayerPictureDisplayAbstract(QWidget* parent = nullptr);
	virtual ~TMultilayerPictureDisplayAbstract() = 0;

	virtual void setPictureDisplayWidget(TPictureDisplayAbstract* widget);
	TPictureDisplayAbstract* pictureDisplayWidget();

private:
	Ui::TMultilayerPictureDisplayAbstractClass* ui;
};

#endif // !_TMULTILAYERPICTUREDISPLAYABSTRACT_H_
