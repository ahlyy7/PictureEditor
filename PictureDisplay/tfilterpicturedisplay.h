#pragma once

#ifndef _TFILTERPICTUREDISPLAY_H_
#define _TFILTERPICTUREDISPLAY_H_

#include "tmultilayerpicturedisplayabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TFilterPictureDisplayClass; };
QT_END_NAMESPACE

class TFilterWindowAbstract;

class TFilterPictureDisplay : public TMultilayerPictureDisplayAbstract
{
	Q_OBJECT

private:
	TPictureDisplayAbstract* after;
	TFilterWindowAbstract* before;

	//QSize filterSize;

	void reZorder();

protected:
	virtual void paintEvent(QPaintEvent* event) override;

public:
	virtual void setPictureDisplayWidget(TPictureDisplayAbstract* widget) override;
	//void setAfterPictureDisplay(TPictureDisplayAbstract* after);
	void setBeforeFilterWindow(TFilterWindowAbstract* before);
	TFilterWindowAbstract* getBeforeFilterWindow() const;

	virtual void setPixmap(const QPixmap& pixmap) override;
	virtual QSize getPixmapSize() override;

	TFilterPictureDisplay(QWidget* parent = nullptr);
	~TFilterPictureDisplay();

private:
	Ui::TFilterPictureDisplayClass* ui;
};

#endif // !_TFILTERPICTUREDISPLAY_H_
