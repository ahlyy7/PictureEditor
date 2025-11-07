#pragma once

#ifndef _TALTEREDFILTERWINDOWABSTRACT_H_
#define _TALTEREDFILTERWINDOWABSTRACT_H_

#include "tfilterwindowabstract.h"
#include <QPen>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class TAlteredFilterWindowAbstractClass; };
QT_END_NAMESPACE

class TGraphicsItemAbstract;

class TGraffitiFilterWindowAbstract : public TFilterWindowAbstract
{
	Q_OBJECT

private:
	bool cancel;
	bool moving;

	bool unsetMoveCursor;
	bool unsetPressMoveCursor;
	QCursor mouseMoveCursor;
	QCursor mousePressMoveCursor;

	QPoint beginPoint;
	QPoint previousPoint;
	QPoint movePoint;

	QPen pen;
	QBrush brush;

	void setMouseMoveCursor();
	void setMousePressMoveCursor();

protected:
	virtual TGraphicsItemAbstract* createGraphicsItem() = 0;

	virtual void keyPressEvent(QKeyEvent* event) override;
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;

	virtual void cancelProcess(const QPoint& beginPoint, const QPoint& cancelPoint) = 0;
	virtual void mousePressProcess(const QPoint& point) = 0;
	virtual void mouseMoveProcess(const QPoint& beginPoint, const QPoint& previousPoint, const QPoint& movePoint) = 0;
	virtual void mouseReleaseProcess(const QPoint& beginPoint, const QPoint& endPoint) = 0;

public:
	TGraffitiFilterWindowAbstract(QWidget* parent = nullptr);
	~TGraffitiFilterWindowAbstract() = 0;

	void setMouseMoveCursor(QCursor cursor);
	void unsetMouseMoveCursor(bool unset = true);
	QCursor getMouseMoveCursor();

	void setMousePressMoveCursor(QCursor cursor);
	void unsetMousePressMoveCursor(bool unset = true);
	QCursor getMousePressMoveCursor();

	TGraphicsItemAbstract* tryCreateGraphicsItem();

	void setPen(const QPen& pen);
	const QPen& getPen() const;

	void setBrush(const QBrush& brush);
	const QBrush& getBrush() const;

signals:
	void canceled(const QPoint& beginPoint, const QPoint& cancelPoint);
	void mousePressed(const QPoint& point);
	void mouseMoved(const QPoint& beginPoint, const QPoint& previousPoint, const QPoint& movePoint);
	void mouseReleased(const QPoint& beginPoint, const QPoint& endPoint);

private:
	Ui::TAlteredFilterWindowAbstractClass* ui;
};

#endif // !_TALTEREDFILTERWINDOWABSTRACT_H_
