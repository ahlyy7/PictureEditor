#pragma once

#ifndef _TLINEGRAFFITIFILTERWINDOW_H_
#define _TLINEGRAFFITIFILTERWINDOW_H_

#include "tgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TLineGraffitiFilterWindowClass; };
QT_END_NAMESPACE

class TLineGraphicsItem;

class TLineGraffitiFilterWindow : public TGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	std::unique_ptr<TLineGraphicsItem> lineGraphicsItemPainter;
	std::unique_ptr<TLineGraphicsItem> lineGraphicsItem;

protected:
	void paintEvent(QPaintEvent* event) override;

public:
	TLineGraffitiFilterWindow(QWidget* parent = nullptr);
	~TLineGraffitiFilterWindow();

private:
	Ui::TLineGraffitiFilterWindowClass* ui;

protected:
	// 通过 TGraffitiFilterWindowAbstract 继承
	TGraphicsItemAbstract* createGraphicsItem() override;
	void cancelProcess(const QPoint& beginPointF, const QPoint& cancelPointF) override;
	void mousePressProcess(const QPoint& pointF) override;
	void mouseMoveProcess(const QPoint& beginPointF, const QPoint& previousPointF, const QPoint& movePointF) override;
	void mouseReleaseProcess(const QPoint& beginPointF, const QPoint& endPointF) override;
};

#endif // !_TLINEGRAFFITIFILTERWINDOW_H_
