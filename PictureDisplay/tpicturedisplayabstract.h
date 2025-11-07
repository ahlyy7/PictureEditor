#pragma once

#ifndef _PICTUREDISPLAYABSTRACT_H_
#define _PICTUREDISPLAYABSTRACT_H_

#include "picturedisplay_global.h"
#include <QtWidgets/QWidget>

class PICTUREDISPLAY_EXPORT TPictureDisplayAbstract : public QWidget
{
    Q_OBJECT

public:
    virtual void setPixmap(const QPixmap& pixmap) = 0;
    virtual QSize getPixmapSize() = 0;

    TPictureDisplayAbstract(QWidget* parent = nullptr);
    virtual ~TPictureDisplayAbstract() = 0;
};

#endif // !_PICTUREDISPLAYABSTRACT_H_
