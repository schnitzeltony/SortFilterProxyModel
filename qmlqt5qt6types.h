#ifndef QMLQT5QT6TYPES_H
#define QMLQT5QT6TYPES_H

#include <QtGlobal>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    typedef int qmllistcount;
#else
    typedef qsizetype qmllistcount;
#endif

#endif // QMLQT5QT6TYPES_H
