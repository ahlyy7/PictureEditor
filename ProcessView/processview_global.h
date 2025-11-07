#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PROCESSVIEW_LIB)
#  define PROCESSVIEW_EXPORT Q_DECL_EXPORT
# else
#  define PROCESSVIEW_EXPORT Q_DECL_IMPORT
# endif
#else
# define PROCESSVIEW_EXPORT
#endif
