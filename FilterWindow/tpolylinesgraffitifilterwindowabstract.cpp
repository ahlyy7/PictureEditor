#include "ui_tpolylinesgraffitifilterwindowabstract.h"
#include "tpolylinesgraffitifilterwindowabstract.h"
#include "tpolylinesgraphicsitemabstract.h"
#include <QPainter>

void TPolylinesGraffitiFilterWindowAbstract::paintEvent(QPaintEvent* event)
{
	if (isOver)
		return;

	QPainter painter(this);
	painter.setWindow({ { 0, 0 }, getImageSize() });

	//polyLinesGraphicsItemPainter->tryDrawGrahicesItem(&painter);
	paint(&painter);
}

void TPolylinesGraffitiFilterWindowAbstract::setPolyLinesGraphicsItemPainter(TPolyLinesGraphicsItemAbstract* polyLinesGraphicsItemPainter)
{
	this->polyLinesGraphicsItemPainter.reset(polyLinesGraphicsItemPainter);
}

TPolyLinesGraphicsItemAbstract* TPolylinesGraffitiFilterWindowAbstract::getPolyLinesGraphicsItemPainter() const
{
	return polyLinesGraphicsItemPainter.get();
}

TPolylinesGraffitiFilterWindowAbstract::TPolylinesGraffitiFilterWindowAbstract(QWidget *parent)
	: TGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TPolylinesGraffitiFilterWindowAbstractClass())
	, isOver(false)
{
	ui->setupUi(this);
}

TPolylinesGraffitiFilterWindowAbstract::~TPolylinesGraffitiFilterWindowAbstract()
{
	delete ui;
}

//TGraphicsItemAbstract* TPolylinesGraffitiFilterWindowAbstract::createGraphicsItem()
//{
//	if (polyLinesGraphicsItemPainter->getPolyLines().size() < 2)
//		return nullptr;
//
//	auto polylinesGraphicsItem = new TPolyLinesGraphicsItemAbstract(*polyLinesGraphicsItemPainter);
//
//	return polylinesGraphicsItem;
//}

void TPolylinesGraffitiFilterWindowAbstract::cancelProcess(const QPoint& beginPoint, const QPoint& cancelPoint)
{
	isOver = true;
	repaint();
}

void TPolylinesGraffitiFilterWindowAbstract::mousePressProcess(const QPoint& point)
{
	polyLinesGraphicsItemPainter->setPen(getPen());
	polyLinesGraphicsItemPainter->setBrush(getBrush());
	polyLinesGraphicsItemPainter->setPolyLines({});

	polylinesPainter.clear();
	polylinesPainter.append(point);
	isOver = false;
}

void TPolylinesGraffitiFilterWindowAbstract::mouseMoveProcess(const QPoint& beginPoint, const QPoint& previousPoint, const QPoint& movePoint)
{
	auto [x, y] = movePoint - polylinesPainter.back();
	auto distance = std::sqrt(x * x + y * y);
	if (distance * 2.0 < getPen().widthF())
		return;

	polylinesPainter.append(movePoint);
	polyLinesGraphicsItemPainter->setPolyLines(polylinesPainter);

	repaint();
}

void TPolylinesGraffitiFilterWindowAbstract::mouseReleaseProcess(const QPoint& beginPoint, const QPoint& endPoint)
{
	polyLinesGraphicsItemPainter->setPolyLines(std::move(polylinesPainter));
	isOver = true;
	repaint();
}
