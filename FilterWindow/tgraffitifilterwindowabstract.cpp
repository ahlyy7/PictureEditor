#include "ui_tgraffitifilterwindowabstract.h"
#include "tgraffitifilterwindowabstract.h"
#include <qevent.h>
#include "tgraphicsitemabstract.h"

void TGraffitiFilterWindowAbstract::setMouseMoveCursor()
{
	if (unsetMoveCursor)
		unsetCursor();
	else
		setCursor(mouseMoveCursor);
}

void TGraffitiFilterWindowAbstract::setMousePressMoveCursor()
{
	if (unsetPressMoveCursor)
		unsetCursor();
	else
		setCursor(mousePressMoveCursor);
}

void TGraffitiFilterWindowAbstract::keyPressEvent(QKeyEvent* event)
{
	auto key = event->key();

	if (!moving || key != Qt::Key_Escape)
	{
		event->ignore();
		return;
	}

	if (!cancel)
	{
		cancel = true;

		cancelProcess(beginPoint, movePoint);

		emit canceled(beginPoint, movePoint);
	}

	event->accept();
}

void TGraffitiFilterWindowAbstract::mousePressEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		event->ignore();
		return;
	}

	moving = true;

	setMousePressMoveCursor();

	beginPoint = previousPoint = movePoint = (event->position() / getScale()).toPoint();

	mousePressProcess(beginPoint);

	emit mousePressed(beginPoint);

	event->accept();
}

void TGraffitiFilterWindowAbstract::mouseMoveEvent(QMouseEvent* event)
{
	if (!moving)
	{
		event->ignore();
		return;
	}

	if (cancel)
	{
		event->accept();
		return;
	}

	movePoint = (event->position() / getScale()).toPoint();
	mouseMoveProcess(beginPoint, previousPoint, movePoint);
	emit mouseMoved(beginPoint, previousPoint, movePoint);
	previousPoint = movePoint;

	event->accept();
}

void TGraffitiFilterWindowAbstract::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		event->ignore();
		return;
	}

	setMouseMoveCursor();

	movePoint = (event->position() / getScale()).toPoint();

	if (!cancel)
	{
		mouseReleaseProcess(beginPoint, movePoint);
		emit mouseReleased(beginPoint, movePoint);
	}

	moving = false;
	cancel = false;

	event->accept();
}

TGraffitiFilterWindowAbstract::TGraffitiFilterWindowAbstract(QWidget *parent)
	: TFilterWindowAbstract(parent)
	, ui(new Ui::TAlteredFilterWindowAbstractClass())
	, cancel(false)
	, moving(false)
	, unsetMoveCursor(true)
	, unsetPressMoveCursor(true)
{
	ui->setupUi(this);

	setMousePressMoveCursor(Qt::CrossCursor);

	setFocusPolicy(Qt::ClickFocus);
}

TGraffitiFilterWindowAbstract::~TGraffitiFilterWindowAbstract()
{
	delete ui;
}

void TGraffitiFilterWindowAbstract::setMouseMoveCursor(QCursor cursor)
{
	unsetMouseMoveCursor(false);
	mouseMoveCursor = cursor;
}

void TGraffitiFilterWindowAbstract::unsetMouseMoveCursor(bool unset)
{
	unsetMoveCursor = unset;
}

QCursor TGraffitiFilterWindowAbstract::getMouseMoveCursor()
{
	return mouseMoveCursor;
}

void TGraffitiFilterWindowAbstract::setMousePressMoveCursor(QCursor cursor)
{
	unsetMousePressMoveCursor(false);
	mousePressMoveCursor = cursor;
}

void TGraffitiFilterWindowAbstract::unsetMousePressMoveCursor(bool unset)
{
	unsetPressMoveCursor = unset;
}

QCursor TGraffitiFilterWindowAbstract::getMousePressMoveCursor()
{
	return mousePressMoveCursor;
}

TGraphicsItemAbstract* TGraffitiFilterWindowAbstract::tryCreateGraphicsItem()
{
	auto result = createGraphicsItem();
	if (!result)
		return nullptr;

	result->setPen(pen);
	result->setBrush(brush);

	return result;
}

void TGraffitiFilterWindowAbstract::setPen(const QPen& pen)
{
	this->pen = pen;
}

const QPen& TGraffitiFilterWindowAbstract::getPen() const
{
	return pen;
}

void TGraffitiFilterWindowAbstract::setBrush(const QBrush& brush)
{
	this->brush = brush;
}

const QBrush& TGraffitiFilterWindowAbstract::getBrush() const
{
	return brush;
}
