#pragma once

#ifndef _QTSTDSTRINGSUPPORT_H_
#define _QTSTDSTRINGSUPPORT_H_

#include <string>
#include <QString>

std::string toStdString(const QString& str);
QString toQtString(const std::string& str);

#endif // !_QTSTDSTRINGSUPPORT_H_
