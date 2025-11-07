#include "ui_tbrushgraffitifilterwindowabstract.h"
#include "tbrushgraffitifilterwindowabstract.h"
#include "tbrushgraphicsitemabstract.h"
#include <QPainter>
#include <qevent.h>

TBrushGraffitiFilterWindowAbstract::TBrushGraffitiFilterWindowAbstract(QWidget *parent)
	: TGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TBrushGraffitiFilterWindowAbstractClass())
	, cancel(false)
{
	ui->setupUi(this);
}

TBrushGraffitiFilterWindowAbstract::~TBrushGraffitiFilterWindowAbstract()
{
	delete ui;
}

void TBrushGraffitiFilterWindowAbstract::setBrushGrahicsItem(TBrushGraphicsItemAbstract* brushGraphicsItem)
{
	this->brushGraphicsItem.reset(brushGraphicsItem);
}

TBrushGraphicsItemAbstract* TBrushGraffitiFilterWindowAbstract::getBrushGrahicsItem() const
{
	return brushGraphicsItem.get();
}

void TBrushGraffitiFilterWindowAbstract::cancelProcess(const QPoint& beginPoint, const QPoint& cancelPoint)
{
	cancel = true;
	repaint();
}

void TBrushGraffitiFilterWindowAbstract::mousePressProcess(const QPoint& point)
{
	brushGraphicsItem->setPen(getPen());
	brushGraphicsItem->setBrush(getBrush());

	brushGraphicsItem->setRect({ point, point });

	cancel = false;
}

void TBrushGraffitiFilterWindowAbstract::mouseMoveProcess(const QPoint& beginPoint, const QPoint& previousPoint, const QPoint& movePoint)
{
	brushGraphicsItem->setRect({ beginPoint, movePoint });

	repaint();
}

void TBrushGraffitiFilterWindowAbstract::mouseReleaseProcess(const QPoint& beginPoint, const QPoint& endPoint)
{
	brushGraphicsItem->setRect({ beginPoint, endPoint });

	cancel = true;
	repaint();
}

void TBrushGraffitiFilterWindowAbstract::paintEvent(QPaintEvent* event)
{
	if (cancel)
		return;

	QPainter painter(this);
	painter.setWindow({ { 0, 0 }, getImageSize() });

	brushGraphicsItem->tryDrawGrahicesItem(&painter);

	event->accept();
}
