/*
MessageCenterRequests class declarations of ModPlug Player
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

namespace ModPlugPlayer::MessageCenterRequests {
    class SongRequests : public QObject {
        Q_OBJECT
    signals:
        void openRequested();
        void openRequested(const std::filesystem::path filePath);
        void stopRequested();
        void stopRequested(const PlayListItem playListItem);
        void playRequested();
        void playRequested(const PlayListItem playListItem);
        void pauseRequested();
        void pauseRequested(const PlayListItem playListItem);
        void resumeRequested();
        void resumeRequested(const PlayListItem playListItem);
        void previousRequested();
        void nextRequested();
        void rewindRequested();
        void fastForwardRequested();
        void volumeChangeRequested(const int volume);
        void timeScrubbingRequested(const int position);
        void repeatModeChangeRequested(const ModPlugPlayer::RepeatMode repeatMode);
    };

    class WindowRequests : public QObject {
        Q_OBJECT
    signals:
        void alwaysOnTopStateChangeRequested(const bool alwaysOnTop);
        void titleBarHidingStateChangeRequested(const bool hide);
        void snappingToViewPortStateChangeRequested(const bool toBeSnappedToViewPort);
        void keepingStayingInViewPortStateChangeRequested(const bool toBeKeptStayingInViewPort);
        void setupRequested();
    };
    class SoundRequests : public QObject {
        Q_OBJECT
    signals:
        void eqStateChangeRequested(const bool activated);
        void dspStateChangeRequested(const bool activated);
        void amigaFilterChangeRequested(const AmigaFilter amigaFilter);
        void interpolationFilterChangeRequested(const InterpolationFilter interpolationFilter);
    };

    class Requests : public QObject {
        Q_OBJECT
    public:
        SongRequests songRequests;
        WindowRequests windowRequests;
        SoundRequests soundRequests;
    };
}
