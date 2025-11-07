#pragma once

#ifndef _TNORMALPICTUREDISPLAY_H_
#define _TNORMALPICTUREDISPLAY_H_

#include "tpicturedisplayabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class normalPictureDisplayClass; };
QT_END_NAMESPACE

class TNormalPictureDisplay : public TPictureDisplayAbstract
{
	Q_OBJECT

private:
	QSize pixmapSize;

public:
	TNormalPictureDisplay(QWidget* parent = nullptr);
	virtual ~TNormalPictureDisplay() override;

	virtual void setPixmap(const QPixmap& pixmap) override;
	virtual QSize getPixmapSize() override;

private:
	Ui::normalPictureDisplayClass* ui;
};

#endif // !_TNORMALPICTUREDISPLAY_H_
