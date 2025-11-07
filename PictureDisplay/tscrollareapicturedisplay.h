#pragma once

#include "tmultilayerpicturedisplayabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TScrollAreaPictureDisplayClass; };
QT_END_NAMESPACE

class TScrollAreaPictureDisplay : public TMultilayerPictureDisplayAbstract
{
	Q_OBJECT

private:
	//TPictureDisplayAbstract* pictureDisplay;
	QPixmap pixmap;
	double proportion;
	QSize changeSize;
	bool isScaling;
	bool isMoving;
	QPointF moveBegin;
	QPointF scrollLocation;

	double minScale;
	double maxScale;

	void paintPixmap();

	void setProportion(double proportion);
	void setChangeSize(QSize displaySize);

public:
	void moveHorizontal(int delta);
	void moveVertical(int delta);
	void moveScrollBar(QPoint delta);

	void setHorizontal(int value);
	void setVertical(int value);
	void setScrollBar(QPoint value);

	int getHorizontal();
	int getVertical();
	QPoint getScrollBar();

	void setMinScale(double value);
	double getMinScale();

	void setMaxScale(double value);
	double getMaxScale();

protected:
	virtual bool eventFilter(QObject* watched, QEvent* event) override;

	virtual void enterEvent(QEnterEvent* event) override;
	virtual void leaveEvent(QEvent* event) override;

	virtual void resizeEvent(QResizeEvent* event) override;

public:
	QSize getChangeSize();

	virtual void setPixmap(const QPixmap& pixmap) override;
	virtual QSize getPixmapSize() override;

	TScrollAreaPictureDisplay(QWidget *parent = nullptr);
	virtual ~TScrollAreaPictureDisplay() override;

	virtual void setPictureDisplayWidget(TPictureDisplayAbstract* widget) override;
	//virtual TPictureDisplayAbstract* pictureDisplayWidget() override;

	void setScale(double proportion);
	double scale();

	void scaleToWidth(int width);
	void scaleToHeight(int height);
	QSize scaleSize();

signals:
	void scaleChanged(double proportion);
	void displaySizeChanged(QSize displaySize);
	void sizeChanged(QSize size);

private:
	Ui::TScrollAreaPictureDisplayClass *ui;
};
