// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#pragma once

#include "src/utils/desktopinfo.h"
#include <QObject>
#include <QScreen>

class ScreenGrabber : public QObject
{
    Q_OBJECT
public:
    explicit ScreenGrabber(QObject* parent = nullptr);
    QPixmap grabEntireDesktop(bool& ok);
    QPixmap grabScreen(QScreen* screenNumber, bool& ok);
    void correctWaylandDpr(QPixmap& res);
    void freeDesktopPortal(bool& ok, QPixmap& res);
    void generalGrimScreenshot(bool& ok, QPixmap& res);
    QRect desktopGeometry();
    QRect logicalDesktopGeometry();
    static QPixmap copyLogicalSelection(const QPixmap& pixmap,
                                        QRect& selection);

private:
    DesktopInfo m_info;
};
