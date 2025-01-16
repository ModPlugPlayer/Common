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
#include <Interfaces/PlayerSignals.hpp>

namespace ModPlugPlayer {
    class MessageCenter : public QObject,
                          public Interfaces::PlayerSignals
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
        void openRequested() override;
        void openRequested(const std::filesystem::path filePath) override;
        void stopRequested() override;
        void stopRequested(const PlayListItem playListItem) override;
        void playRequested() override;
        void playRequested(const PlayListItem playListItem) override;
        void pauseRequested() override;
        void pauseRequested(const PlayListItem playListItem) override;
        void resumeRequested() override;
        void resumeRequested(const PlayListItem playListItem) override;
        void previousRequested() override;
        void nextRequested() override;
        void volumeChangeRequested(const int volume) override;
        void timeScrubbingRequested(const int position) override;
        void repeatModeChangeRequested(const ModPlugPlayer::RepeatMode repeatMode) override;
        void eqStateChangeRequested(const bool activated) override;
        void dspStateChangeRequested(const bool activated) override;
        void alwaysOnTopStateChangeRequested(const bool alwaysOnTop) override;
        void titleBarHidingStateChangeRequested(const bool hide) override;
        void snappingToViewPortStateChangeRequested(const bool toBeSnappedToViewPort) override;
        void keepingStayingInViewPortStateChangeRequested(const bool toBeKeptStayingInViewPort) override;
        void amigaFilterChangeRequested(const AmigaFilter amigaFilter) override;
        void interpolationFilterChangeRequested(const InterpolationFilter interpolationFilter) override;

        //Response Signals
        void loaded(const SongFileInfo songFileInfo, bool successfull) override;
        void loaded(const PlayListItem playListItem, bool successfull) override;
        void stopped() override;
        void stopped(const PlayListItem playListItem) override;
        void playingStarted() override;
        void playingStarted(const SongFileInfo songFileInfo) override;
        void playingStarted(const PlayListItem playListItem) override;
        void paused() override;
        void paused(const SongFileInfo songFileInfo) override;
        void paused(const PlayListItem playListItem) override;
        void resumed() override;
        void resumed(const SongFileInfo songFileInfo) override;
        void resumed(const PlayListItem playListItem) override;
        void previous() override;
        void next() override;
        void volumeChanged(const int volume) override;
        void timeScrubbed(const int position) override;
        void repeatModeChanged(const RepeatMode repeat) override;
        void eqStateChanged(const bool activated) override;
        void dspStateChanged(const bool activated) override;
        void alwaysOnTopStateChanged(const bool alwaysOnTop) override;
        void titleBarHidingStateChanged(const bool hide) override;
        void snappingToViewPortStateChanged(const bool snapToViewPort) override;
        void keepingStayingInViewPortStateChanged(const bool toBeKeptStayingInViewPort) override;
        void elapsedTimeChanged(const int seconds) override;
        void trackDurationChanged(const size_t songDurationSeconds) override;
        void trackTitleChanged(const QString songTitle) override;
        void amigaFilterChanged(const AmigaFilter amigaFilter) override;
        void interpolationFilterChanged(const InterpolationFilter interpolationFilter) override;
    };
}
