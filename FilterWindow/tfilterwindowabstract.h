#pragma once

#ifndef _TFILTERWINDOWABSTRACT_H_
#define _TFILTERWINDOWABSTRACT_H_

#include <QWidget>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class TFilterWindowAbstractClass; };
QT_END_NAMESPACE

class TFilterWindowAbstract : public QWidget
{
	Q_OBJECT

private:
	QSize imageSize;
	double scale;

protected:
	//virtual void paintEvent(QPaintEvent* event) override = 0;

	virtual void resizeEvent(QResizeEvent* event) override;

public:
	double getScale() const;
	TFilterWindowAbstract(QWidget* parent = nullptr);
	virtual ~TFilterWindowAbstract() = 0;

	virtual void setImageSize(QSize imageSize);
	QSize getImageSize() const;

private:
	Ui::TFilterWindowAbstractClass* ui;
};

#endif // !_TFILTERWINDOWABSTRACT_H_
