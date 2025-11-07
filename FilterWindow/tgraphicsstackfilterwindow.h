#pragma once

#ifndef _TGRAPHICSFILTERWINDOW_H_
#define _TGRAPHICSFILTERWINDOW_H_

#include "tfilterwindowabstract.h"
#include <vector>
#include <memory>
#include "tgraphicsitemabstract.h"
#include <utility>

QT_BEGIN_NAMESPACE
namespace Ui { class TGraphicsFilterWindowClass; };
QT_END_NAMESPACE

class TGraphicsStackFilterWindow : public TFilterWindowAbstract
{
	Q_OBJECT

private:
	std::vector<std::unique_ptr<TGraphicsItemAbstract>> graphicsItems;
	size_t currentIndex;

	QPixmap pixmap;

	void setCurrentIndex(size_t index);

	void paintGraphicsItems(QPaintDevice* paintDevice);

protected:
	void paintEvent(QPaintEvent* event) override;

public:
	std::pair<std::vector<std::unique_ptr<TGraphicsItemAbstract>>::const_iterator, std::vector<std::unique_ptr<TGraphicsItemAbstract>>::const_iterator> getGraphicsItems() const;

	void clear();

	virtual void setImageSize(QSize imageSize);

	void pushGraphicsItem(TGraphicsItemAbstract* graphicsItem);
	void fallbackGraphicsItem();
	void forwardGraphicsItem();

	TGraphicsStackFilterWindow(QWidget* parent = nullptr);
	~TGraphicsStackFilterWindow();

	size_t getCurrentSize();

signals:
	//void emptyed(bool empty);
	void currentGraphicsItemChanged(size_t currentSize);

	void arrivedFront(bool arrived);
	void arrivedBack(bool arrived);

private:
	Ui::TGraphicsFilterWindowClass* ui;
};

#endif // !_TGRAPHICSFILTERWINDOW_H_
