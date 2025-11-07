#pragma once

#ifndef _TRECTHOLLOWFILTERWINDOW_H_
#define _TRECTHOLLOWFILTERWINDOW_H_

#include "tfilterwindowabstract.h"
#include <QPen>

QT_BEGIN_NAMESPACE
namespace Ui { class TRectHollowFilterWindowClass; };
QT_END_NAMESPACE

class TRectHollowFilterWindow : public TFilterWindowAbstract
{
	Q_OBJECT

private:
	QRectF frameRect;
	QPen framePen;
	QColor inRgb;
	QColor outRgb;

	bool inRectAndFrame;
	bool onLeft, onRight;
	bool onTop, onBottom;

	bool mousePressed;
	bool cancelOperation;

	QRectF beginFrameRect;
	QPointF beginPoint;

	QSize oldSize;

protected:
	virtual void paintEvent(QPaintEvent* event) override;
	virtual void resizeEvent(QResizeEvent* event) override;

	virtual bool event(QEvent* event) override;

	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;

	virtual void keyPressEvent(QKeyEvent* event) override;

public:
	void setFrameRect(const QRectF& frameRect);

	void setFramePen(QPen pen);
	void setInRgb(int red, int green, int blue, int alpha = 255);
	void setOutRgb(int red, int green, int blue, int alpha = 255);

	TRectHollowFilterWindow(QWidget* parent = nullptr);
	virtual ~TRectHollowFilterWindow() override;

signals:
	void frameRectChanged(const QRectF& frameRect);
	void framePenChanged(QPen pen);
	void inRgbChanged(const QColor& color);
	void outRgbChanged(const QColor& color);

private:
	Ui::TRectHollowFilterWindowClass* ui;
};

#endif // !_TRECTHOLLOWFILTERWINDOW_H_
