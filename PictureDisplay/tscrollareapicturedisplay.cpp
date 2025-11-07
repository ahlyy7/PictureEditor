#include "ui_tscrollareapicturedisplay.h"
#include "tscrollareapicturedisplay.h"
#include <QVBoxLayout>
#include <qevent.h>
#include <QScrollBar>

TScrollAreaPictureDisplay::TScrollAreaPictureDisplay(QWidget *parent)
	: TMultilayerPictureDisplayAbstract(parent)
	, ui(new Ui::TScrollAreaPictureDisplayClass())
	//, pictureDisplay(nullptr)
	, proportion(1.0F)
	, isScaling(false)
	, isMoving(false)
	, minScale(1.0F)
	, maxScale(1.0F)
{
	ui->setupUi(this);

	//ui->centralWidget->setFocusPolicy(Qt::ClickFocus);

	ui->centralWidget->installEventFilter(this);
}

TScrollAreaPictureDisplay::~TScrollAreaPictureDisplay()
{
	delete ui;
}

void TScrollAreaPictureDisplay::setPictureDisplayWidget(TPictureDisplayAbstract* widget)
{
	//for (auto widget : ui->centralWidget->findChildren<QWidget*>(Qt::FindChildrenRecursively))
	//	delete widget;
	if (pictureDisplay == widget)
		return;

	delete pictureDisplay;
	widget->setParent(ui->centralWidget);
	ui->centralWidget->layout()->addWidget(widget);
	pictureDisplay = widget;
}

void TScrollAreaPictureDisplay::setScale(double proportion)
{
	setProportion(proportion);
	setChangeSize(pixmap.size() * this->proportion);

	paintPixmap();
}

double TScrollAreaPictureDisplay::scale()
{
	return proportion;
}

void TScrollAreaPictureDisplay::scaleToWidth(int width)
{
	setProportion(double(width) / pixmap.width());
	setChangeSize({ width, std::lround(width * pixmap.height() / double(pixmap.width())) });

	paintPixmap();
}

void TScrollAreaPictureDisplay::scaleToHeight(int height)
{
	setProportion(double(height) / pixmap.height());
	setChangeSize({ std::lround(height * pixmap.width() / double(pixmap.height())), height });

	paintPixmap();
}

QSize TScrollAreaPictureDisplay::scaleSize()
{
	return changeSize;
}

void TScrollAreaPictureDisplay::paintPixmap()
{
	auto scaledPixmap = pixmap.scaled(changeSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);

	pictureDisplay->setPixmap(scaledPixmap);
}

void TScrollAreaPictureDisplay::setProportion(double proportion)
{
	proportion = std::clamp(proportion, minScale, maxScale);

	if (proportion == this->proportion)
		return;

	QSizeF size = this->size();
	size /= 2.0;
	QPointF point = { size.width(), size.height() };
	point = mapToGlobal(point);
	point = ui->centralWidget->mapFromGlobal(point);
	point *= (proportion - this->proportion) / proportion;

	moveScrollBar(point.toPoint());

	this->proportion = proportion;

	emit scaleChanged(proportion);
}

void TScrollAreaPictureDisplay::setChangeSize(QSize displaySize)
{
	if (this->changeSize == displaySize)
		return;

	this->changeSize = displaySize;
	emit displaySizeChanged(displaySize);
}

void TScrollAreaPictureDisplay::moveHorizontal(int delta)
{
	QScrollBar* scrollBar = ui->scrollArea->horizontalScrollBar();
	auto value = scrollBar->value();
	value += delta;
	scrollBar->setValue(value);
}

void TScrollAreaPictureDisplay::moveVertical(int delta)
{
	QScrollBar* scrollBar = ui->scrollArea->verticalScrollBar();
	auto value = scrollBar->value();
	value += delta;
	scrollBar->setValue(value);
}

void TScrollAreaPictureDisplay::moveScrollBar(QPoint delta)
{
	moveHorizontal(delta.x());
	moveVertical(delta.y());
}

void TScrollAreaPictureDisplay::setHorizontal(int value)
{
	QScrollBar* scrollBar = ui->scrollArea->horizontalScrollBar();
	scrollBar->setValue(value);
}

void TScrollAreaPictureDisplay::setVertical(int value)
{
	QScrollBar* scrollBar = ui->scrollArea->verticalScrollBar();
	scrollBar->setValue(value);
}

void TScrollAreaPictureDisplay::setScrollBar(QPoint value)
{
	setHorizontal(value.x());
	setVertical(value.y());
}

int TScrollAreaPictureDisplay::getHorizontal()
{
	QScrollBar* scrollBar = ui->scrollArea->horizontalScrollBar();
	return scrollBar->value();
}

int TScrollAreaPictureDisplay::getVertical()
{
	QScrollBar* scrollBar = ui->scrollArea->verticalScrollBar();
	return scrollBar->value();
}

QPoint TScrollAreaPictureDisplay::getScrollBar()
{
	return { getHorizontal(), getVertical() };
}

void TScrollAreaPictureDisplay::setMinScale(double value)
{
	minScale = value;
}

double TScrollAreaPictureDisplay::getMinScale()
{
	return minScale;
}

void TScrollAreaPictureDisplay::setMaxScale(double value)
{
	maxScale = value;
}

double TScrollAreaPictureDisplay::getMaxScale()
{
	return maxScale;
}

bool TScrollAreaPictureDisplay::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == ui->centralWidget)
	{
		if (event->type() == QEvent::KeyPress)
		{
			auto keyEvent = static_cast<QKeyEvent*>(event);
			auto key = keyEvent->key();

			if (key == Qt::Key_Control)
			{
				isScaling = true;
				event->accept();
				return true;
			}
		}
		else if (event->type() == QEvent::KeyRelease)
		{
			auto keyEvent = static_cast<QKeyEvent*>(event);
			auto key = keyEvent->key();

			if (key == Qt::Key_Control)
			{
				isScaling = false;
				event->accept();
				return true;
			}
		}
		else if (event->type() == QEvent::Wheel)
		{
			auto wheelEvent = static_cast<QWheelEvent*>(event);

			if (isScaling)
			{
				auto delta = wheelEvent->angleDelta();
				double y = delta.y() / 2048.0F;

				setScale(proportion + y);

				event->accept();
				return true;
			}
		}
		else if (event->type() == QEvent::MouseButtonPress)
		{
			auto mouseEvent = static_cast<QMouseEvent*>(event);

			if (mouseEvent->button() == Qt::LeftButton)
			{
				QCursor cursor(Qt::ClosedHandCursor);
				ui->centralWidget->setCursor(cursor);

				moveBegin = mouseEvent->globalPosition();
				isMoving = true;
				scrollLocation = getScrollBar();

				event->accept();
				return true;
			}
		}
		else if (event->type() == QEvent::MouseMove)
		{
			auto mouseEvent = static_cast<QMouseEvent*>(event);

			if (isMoving)
			{
				auto targetPoint = mouseEvent->globalPosition();
				auto delta = moveBegin - targetPoint;
				//moveBegin = targetPoint;

				//moveScrollBar(delta.toPoint());
				setScrollBar((scrollLocation + delta).toPoint());

				event->accept();
				return true;
			}
		}
		else if (event->type() == QEvent::MouseButtonRelease)
		{
			auto mouseEvent = static_cast<QMouseEvent*>(event);

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui->centralWidget->unsetCursor();

				isMoving = false;

				event->accept();
				return true;
			}
		}
	}

	return false;
}

void TScrollAreaPictureDisplay::enterEvent(QEnterEvent* event)
{
	ui->centralWidget->setFocus();
}

void TScrollAreaPictureDisplay::leaveEvent(QEvent* event)
{
	ui->centralWidget->clearFocus();
}

void TScrollAreaPictureDisplay::resizeEvent(QResizeEvent* event)
{
	emit sizeChanged(event->size());
}

QSize TScrollAreaPictureDisplay::getChangeSize()
{
	return changeSize;
}

void TScrollAreaPictureDisplay::setPixmap(const QPixmap& pixmap)
{
	this->pixmap = pixmap;
	setScale(proportion);
}

QSize TScrollAreaPictureDisplay::getPixmapSize()
{
	return pictureDisplay ? pictureDisplay->getPixmapSize() : QSize(0, 0);
}
