#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FILTERWINDOW_LIB)
#  define FILTERWINDOW_EXPORT Q_DECL_EXPORT
# else
#  define FILTERWINDOW_EXPORT Q_DECL_IMPORT
# endif
#else
# define FILTERWINDOW_EXPORT
#endif
