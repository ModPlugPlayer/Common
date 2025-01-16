/*
MessageCenter class declarations of ModPlug Player
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

namespace ModPlugPlayer {
    class MessageCenter : public QObject
    {
        Q_OBJECT
    public:
        MessageCenter();
        MessageCenter(MessageCenter const &) = delete;
        void operator =(MessageCenter const &) = delete;
        static MessageCenter& getInstance();
    private:
        static std::mutex mutex;
    signals:
        //Player
        //Request Signals
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
        void volumeChangeRequested(const int volume);
        void timeScrubbingRequested(const int position);
        void repeatModeChangeRequested(const ModPlugPlayer::RepeatMode repeatMode);
        void eqStateChangeRequested(const bool activated);
        void dspStateChangeRequested(const bool activated);
        void alwaysOnTopStateChangeRequested(const bool alwaysOnTop);
        void titleBarHidingStateChangeRequested(const bool hide);
        void snappingToViewPortStateChangeRequested(const bool toBeSnappedToViewPort);
        void keepingStayingInViewPortStateChangeRequested(const bool toBeKeptStayingInViewPort);

        //Response Signals
        void loaded(const std::filesystem::path filePath, bool successfull);
        void loaded(const PlayListItem playListItem, bool successfull);
        void stopped();
        void stopped(const PlayListItem playListItem);
        void playingStarted(SongFileInfo songFileInfo);
        void playingStarted(const PlayListItem playListItem);
        void paused();
        void paused(const PlayListItem playListItem);
        void resumed();
        void resumed(const PlayListItem playListItem);
        void previous();
        void next();
        void volumeChanged(const int volume);
        void timeScrubbed(const int position);
        void repeatModeChanged(const RepeatMode repeat);
        void eqStateChanged(const bool activated);
        void dspStateChanged(const bool activated);
        void alwaysOnTopStateChanged(const bool alwaysOnTop);
        void titleBarHidingStateChanged(const bool hide);
        void snappingToViewPortStateChanged(const bool snapToViewPort);
        void keepingStayingInViewPortStateChanged(const bool toBeKeptStayingInViewPort);

        //Song signals
        void elapsedTimeChanged(const int seconds);
        void trackDurationChanged(const size_t songDurationSeconds);
        void trackTitleChanged(const QString songTitle);
    };
}
