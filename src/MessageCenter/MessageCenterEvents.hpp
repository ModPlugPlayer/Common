/*
MessageCenterEvents class declarations of ModPlug Player
Copyright (C) 2025 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <QObject>
#include <QEvent>
#include <QMainWindow>
#include <APIStructures.hpp>
#include <PlayListDTOs.hpp>

namespace ModPlugPlayer::MessageCenterEvents {
    class SongEvents : public QObject {
        Q_OBJECT
    signals:
        void loaded(const SongFileInfo songFileInfo, bool successfull);
        void loaded(const PlayListItem playListItem, bool successfull);
        void stopped();
        void stopped(const PlayListItem playListItem);
        void playingStarted();
        void playingStarted(const SongFileInfo songFileInfo);
        void playingStarted(const PlayListItem playListItem);
        void paused();
        void paused(const SongFileInfo songFileInfo);
        void paused(const PlayListItem playListItem);
        void resumed();
        void resumed(const SongFileInfo songFileInfo);
        void resumed(const PlayListItem playListItem);
        void elapsedTimeChanged(const int seconds);
        void trackDurationChanged(const size_t songDurationSeconds);
        void trackTitleChanged(const QString songTitle);
        void timeScrubbed(const int position);
        void repeatModeChanged(const RepeatMode repeat);
    };

    class WindowEvents : public QObject {
        Q_OBJECT
    signals:
        void alwaysOnTopStateChanged(const bool alwaysOnTop);
        void titleBarHidingStateChanged(const bool hide);
        void snappingToViewPortStateChanged(const bool snapToViewPort);
        void keepingStayingInViewPortStateChanged(const bool toBeKeptStayingInViewPort);
    };

    class SoundEvents : public QObject {
        Q_OBJECT
    signals:
        void volumeChanged(const int volume);
        void eqStateChanged(const bool activated);
        void dspStateChanged(const bool activated);
        void amigaFilterChanged(const AmigaFilter amigaFilter);
        void interpolationFilterChanged(const InterpolationFilter interpolationFilter);
    };

    class Events : public QObject {
        Q_OBJECT
    public:
        SongEvents songEvents;
        WindowEvents windowEvents;
        SoundEvents soundEvents;
    };
}
