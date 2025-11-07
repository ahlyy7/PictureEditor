#pragma once

#ifndef _TANYQUADRILATERALFILTERWINDOW_H_
#define _TANYQUADRILATERALFILTERWINDOW_H_

#include "tfilterwindowabstract.h"
#include <array>
#include <QPoint>
#include <QPen>

QT_BEGIN_NAMESPACE
namespace Ui { class TAnyQuadrilateralFilterWindowClass; };
QT_END_NAMESPACE

class TAnyQuadrilateralFilterWindow : public TFilterWindowAbstract
{
	Q_OBJECT

private:
	std::array<QPointF, 4> pointFs;

	QPen pointPen;
	QPen linePen;

	QPointF beginPointF;
	QPointF* currentPointF;
	QPointF currentPointFCopy;
	bool cancelMove;

	QSize previousSize;

protected:
	virtual void paintEvent(QPaintEvent* event) override;
	virtual void resizeEvent(QResizeEvent* event) override;

	virtual bool event(QEvent* event) override;
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;

	virtual void keyPressEvent(QKeyEvent* event) override;

public:
	TAnyQuadrilateralFilterWindow(QWidget* parent = nullptr);
	~TAnyQuadrilateralFilterWindow();

	void setPointFs(const std::array<QPointF, 4>& pointFs);
	void setPointFs(const QPointF pointFs[]);
	void setPointF(const QPointF& pointF, int index);
	const std::array<QPointF, 4>& getPointFs();

	void setPointPen(QPen pen);
	QPen getPointPen();

	void setLinePen(QPen pen);
	QPen getLinePen();

signals:
	void pointFsChanged(const std::array<QPointF, 4>& pointFs);

private:
	Ui::TAnyQuadrilateralFilterWindowClass* ui;
};

#endif // !_TANYQUADRILATERALFILTERWINDOW_H_
