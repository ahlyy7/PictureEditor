#pragma once

#ifndef _TGRAFFITIPROCESSVIEWWIDGET_H_
#define _TGRAFFITIPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"
#include <functional>
#include <QPen>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class TGraffitiProcessViewWidgetClass; };
QT_END_NAMESPACE

class TGraffitiFilterWindowAbstract;
class QAction;

class TGraffitiProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

private:
	std::function<TGraffitiFilterWindowAbstract* ()> createGraffiti;

	std::unordered_map<std::string, std::function<TGraffitiFilterWindowAbstract* ()>> mapping;

	QPen pen;
	QBrush brush;

	Qt::PenStyle previousPenStyle;
	Qt::BrushStyle previousBrushStyle;

	QToolButton* currentTool;

	void initializePenStyleButton();
	void initializePenCapStyleButton();
	void initializePenJoinStyleButton();

	void initializeBrushStyleButton();

public:
	TGraffitiProcessViewWidget(QWidget* parent = nullptr);
	~TGraffitiProcessViewWidget();

	TGraffitiFilterWindowAbstract* createGraffitiFilterWindow();

	QAction* getUndoAction();
	QAction* getRedoAction();

	const QPen& getPen() const;
	const QBrush& getBrush() const;

	void setPenColor(const QColor& color);
	void setPenStyle(Qt::PenStyle penStyle);
	void setPenCapStyle(Qt::PenCapStyle penCapStyle);
	void setPenJoinStyle(Qt::PenJoinStyle penJoinStyle);

	void setBrushColor(const QColor& color);
	void setBrushStyle(Qt::BrushStyle brushStyle);

private slots:
	void graffitiToggled(bool checked);

	void setNoPenAndNoBrush();

	void setPenColor();
	void setPenWidth(double width);

	void setBrushColor();

signals:
	void graffitiChanged();

	void penChanged(const QPen& pen);
	void brushChanged(const QBrush& brush);

private:
	Ui::TGraffitiProcessViewWidgetClass* ui;
};

#endif // !_TGRAFFITIPROCESSVIEWWIDGET_H_
