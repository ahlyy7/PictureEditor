#pragma once

#ifndef _TNOGRAFFITIFILTERWINDOW_H_
#define _TNOGRAFFITIFILTERWINDOW_H_

#include "tgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TNoGraffitiFilterWindowClass; };
QT_END_NAMESPACE

class TNoGraffitiFilterWindow : public TGraffitiFilterWindowAbstract
{
	Q_OBJECT

public:
	TNoGraffitiFilterWindow(QWidget* parent = nullptr);
	~TNoGraffitiFilterWindow();

private:
	Ui::TNoGraffitiFilterWindowClass* ui;

protected:
	virtual void keyPressEvent(QKeyEvent* event) override;
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;

	// 通过 TGraffitiFilterWindowAbstract 继承
	TGraphicsItemAbstract* createGraphicsItem() override;
	void cancelProcess(const QPoint& beginPointF, const QPoint& cancelPointF) override;
	void mousePressProcess(const QPoint& pointF) override;
	void mouseMoveProcess(const QPoint& beginPointF, const QPoint& previousPointF, const QPoint& movePointF) override;
	void mouseReleaseProcess(const QPoint& beginPointF, const QPoint& endPointF) override;
};

#endif // !_TNOGRAFFITIFILTERWINDOW_H_
