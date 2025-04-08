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
#include <Parameters.hpp>

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
        void previousRequested(const PlayListItem playListItem);
        void nextRequested();
        void nextRequested(const PlayListItem playListItem);
        void rewindRequested();
        void fastForwardRequested();
        void repeatModeChangeRequested(const ModPlugPlayer::RepeatMode repeatMode);
    };

    class ScrubberRequests : public QObject {
        Q_OBJECT
    signals:
        void scrubbingRequested(const unsigned int position);
        void scrubberUpdatePeriodChangeRequested(const unsigned int updateFrequency);
    };

    class WindowStandardRequests : public QObject {
        Q_OBJECT
    signals:
        void windowOpenRequested();
        void windowCloseRequested();
    };

    class WindowRequests : public QObject {
        Q_OBJECT
    signals:
        void alwaysOnTopStateChangeRequested(const bool alwaysOnTop);
        void titleBarHidingStateChangeRequested(const bool hide);
        void snappingToViewPortStateChangeRequested(const bool toBeSnappedToViewPort);
        void snappingThresholdChangeRequested(const int snappingThreshold);
        void keepingStayingInViewPortStateChangeRequested(const bool toBeKeptStayingInViewPort);
        void minimizeRequested();
        void maximizeRequested();
        void restoreRequested();
        void hideRequested();
        void showRequested();
    };

    class SoundRequests : public QObject {
        Q_OBJECT
    signals:
        void volumeChangeRequested(const int volume);
        void eqStateChangeRequested(const bool activated);
        void dspStateChangeRequested(const bool activated);
        void outputDeviceChangeRequested(const int outputDeviceIndex);
        void soundResolutionChangeRequested(const SampleRate sampleRate, const BitRate bitRate, const ChannelMode channelMode);
    };

    class ModuleRequests : public QObject {
        Q_OBJECT
    signals:
        void amigaFilterChangeRequested(const AmigaFilter amigaFilter);
        void interpolationFilterChangeRequested(const InterpolationFilter interpolationFilter);
    };

    class BarDisplayRequests : public QObject {
        Q_OBJECT
    signals:
        void windowFunctionChangeRequested(const WindowFunction windowFunction);
        void barTypeChangeRequested(const BarType barType);
        void minimumValueChangeRequested(const int maximumValue);
        void maximumValueChangeRequested(const int maximumValue);
        void barLedAmountChangeRequested(const int barLedAmount);
        void ledHeightRatioChangeRequested(const double ledRatio);
        void barWidthRatioChangeRequested(const double barRatio);
        void dimmingRatioChangeRequested(const double dimmingRatio);
        void dimmedTransparencyRatioChangeRequested(const double dimmedTransparencyRatio);
        void barAmountChangeRequested(const int barAmount);
        void gradientChangeRequested(const QGradientStops &gradient);
        void scaleTypeChangeRequested(const bool isLogarithmicScale);
    };

    class Requests : public QObject {
        Q_OBJECT
    public:
        SongRequests songRequests;
        ScrubberRequests scrubberRequests;
        ModuleRequests moduleRequests;
        SoundRequests soundRequests;
        WindowRequests windowRequests;
        BarDisplayRequests spectrumAnalyzerRequests;
        BarDisplayRequests vuMeterRequests;
        struct {
            WindowStandardRequests playerWindowRequests;
            WindowStandardRequests playlistWindowRequests;
            WindowStandardRequests settingsWindowRequests;
            WindowStandardRequests aboutWindowRequests;
        } windowStandardRequests;
    };
}
