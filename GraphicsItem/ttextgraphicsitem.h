#pragma once

#ifndef _TTEXTGRAPHICSITEM_H_
#define _TTEXTGRAPHICSITEM_H_

#include "tbrushgraphicsitemabstract.h"

class QTextOption;

class TTextGraphicsItem : public TBrushGraphicsItemAbstract
{
private:
	QString text;
	std::unique_ptr<QTextOption> textOption;

protected:
	// 通过 TBrushGraphicsItemAbstract 继承
	void drawGrahicsItem(QPainter* painter) const override;

public:
	TTextGraphicsItem();
	TTextGraphicsItem(const TTextGraphicsItem& other);
	TTextGraphicsItem(TTextGraphicsItem&& other) noexcept;

	void setText(const QString& text);
	const QString& getText() const;

	void setTextOption(const QTextOption& textOption);
	const QTextOption& getTextOption() const;
};

#endif // !_TTEXTGRAPHICSITEM_H_
