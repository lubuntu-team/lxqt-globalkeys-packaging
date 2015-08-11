/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXDE-Qt - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2013 Razor team
 * Authors:
 *   Kuzma Shapran <kuzma.shapran@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef GLOBAL_KEY_SHORTCUT_SELECTOR__SHORTCUT_SELECTOR__INCLUDED
#define GLOBAL_KEY_SHORTCUT_SELECTOR__SHORTCUT_SELECTOR__INCLUDED

#include <QToolButton>
#include <QWidget>
#include <QString>


class QTimer;

namespace GlobalKeyShortcut
{
class Client;
}

class ShortcutSelector : public QToolButton
{
    Q_OBJECT
public:
    explicit ShortcutSelector(QWidget *parent = 0);

    QAction *addMenuAction(const QString &title);

    bool shortcutAutoApplied(void) const { return mAutoApplyShortcut; }

    bool isGrabbing() const;

signals:
    void shortcutGrabbed(const QString &);

public slots:
    void grabShortcut(int timeout = 10);

    void clear();

    void autoApplyShortcut(bool value = true) { mAutoApplyShortcut = value; }

    void cancelNow();

private slots:
    void shortcutTimer_timeout();
    void grabShortcut_fail();
    void newShortcutGrabbed(const QString &);

private:
    GlobalKeyShortcut::Client *mClient;
    QString mOldShortcut;
    int mTimeoutCounter;
    QTimer *mShortcutTimer;
    bool mAutoApplyShortcut;
};

#endif // GLOBAL_KEY_SHORTCUT_SELECTOR__SHORTCUT_SELECTOR__INCLUDED
