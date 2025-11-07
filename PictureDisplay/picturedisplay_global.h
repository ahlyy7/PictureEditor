#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PICTUREDISPLAY_LIB)
#  define PICTUREDISPLAY_EXPORT Q_DECL_EXPORT
# else
#  define PICTUREDISPLAY_EXPORT Q_DECL_IMPORT
# endif
#else
# define PICTUREDISPLAY_EXPORT
#endif
