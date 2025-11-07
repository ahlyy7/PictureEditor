#pragma once

#ifndef _TNOTOPENWIDGET_H_
#define _TNOTOPENWIDGET_H_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TNotOpenWidgetClass; };
QT_END_NAMESPACE

class QMouseEvent;

class TNotOpenWidget : public QWidget
{
	Q_OBJECT

private:
	bool visible;

	void setVisibleBackGround(bool visible);

protected:
	virtual bool eventFilter(QObject* watched, QEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;

public:
	TNotOpenWidget(QWidget* parent = nullptr);
	~TNotOpenWidget();

signals:
	void clicked();

private:
	Ui::TNotOpenWidgetClass* ui;
};

#endif // !_TNOTOPENWIDGET_H_
