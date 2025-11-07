#pragma once

#ifndef _TNORMALMULTILAYERPICTUREDISPLAY_H_
#define _TNORMALMULTILAYERPICTUREDISPLAY_H_

#include "tmultilayerpicturedisplayabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TNormalMultilayerPictureDisplayClass; };
QT_END_NAMESPACE

class TNormalMultilayerPictureDisplay : public TMultilayerPictureDisplayAbstract
{
	Q_OBJECT

public:
	TNormalMultilayerPictureDisplay(QWidget* parent = nullptr);
	~TNormalMultilayerPictureDisplay();

	// 通过 TMultilayerPictureDisplayAbstract 继承
	void setPixmap(const QPixmap& pixmap) override;
	QSize getPixmapSize() override;

private:
	Ui::TNormalMultilayerPictureDisplayClass* ui;
};

#endif // !_TNORMALMULTILAYERPICTUREDISPLAY_H_
