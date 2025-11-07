#include "pch.h"
#include "ttextgraphicsitem.h"
#include <QPainter>
#include <QTextOption>

static void stringReverse(QString* string);

void TTextGraphicsItem::drawGrahicsItem(QPainter* painter) const
{
	auto rect = getRect();
	auto [left, top] = rect.topLeft();
	auto [right, bottom] = rect.bottomRight();

	if (top > bottom)
	{
		std::swap(top, bottom);
		rect.setTop(top);
		rect.setBottom(bottom);
	}
	if (left > right)
	{
		std::swap(left, right);
		rect.setLeft(left);
		rect.setRight(right);
	}

	QFont font = painter->font(), previousFont = font;
	font.setPointSizeF(getPen().widthF());
	painter->setFont(font);

	painter->drawText(rect, text, *textOption);

	painter->setFont(previousFont);
}

TTextGraphicsItem::TTextGraphicsItem()
	: textOption(new QTextOption())
{
}

TTextGraphicsItem::TTextGraphicsItem(const TTextGraphicsItem& other)
	: TBrushGraphicsItemAbstract(other)
	, text(other.text)
	, textOption(new QTextOption(*other.textOption))
{
}

TTextGraphicsItem::TTextGraphicsItem(TTextGraphicsItem&& other) noexcept
	: TBrushGraphicsItemAbstract(other)
	, text(std::move(other.text))
	, textOption(std::move(other.textOption))
{
}

void TTextGraphicsItem::setText(const QString& text)
{
	this->text = text;

	if (textOption->textDirection() == Qt::RightToLeft)
		stringReverse(&this->text);
}

const QString& TTextGraphicsItem::getText() const
{
	return text;
}

void TTextGraphicsItem::setTextOption(const QTextOption& textOption)
{
	auto previous = this->textOption->textDirection(), current = textOption.textDirection();

	if (previous != current)
		stringReverse(&text);

	*this->textOption = textOption;
}

const QTextOption& TTextGraphicsItem::getTextOption() const
{
	return *textOption;
}

void stringReverse(QString* string)
{
	if (string->isEmpty())
		return;

	auto list = string->split('\n');
	string->clear();

	for (const auto& split : list)
	{
		auto ucs4 = split.toUcs4();
		std::reverse(ucs4.begin(), ucs4.end());
		string->append(QString::fromUcs4((const char32_t*)(ucs4.constData()), ucs4.size())).append('\n');
	}

	string->removeLast();
}
