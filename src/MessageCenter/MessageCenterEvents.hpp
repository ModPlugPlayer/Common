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
#include <Parameters.hpp>

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
        void elapsedTimeChanged(const int elapsedTimeSeconds);
        void globalRowIndexChanged(const int globalRowIndex);
        void songDurationChanged(const size_t songDurationSeconds);
        void songTitleChanged(const std::string songTitle);
        void timeScrubbed(const int position);
        void repeatModeChanged(const RepeatMode repeatMode);
    };

    class ScrubberEvents : public QObject {
        Q_OBJECT
    signals:
        void scrubberUpdatePeriodChanged(const unsigned int updateFrequency);
        void scrubberStepsAmountChanged(const unsigned int stepsAmount);
        void scrubberPositionChanged(const unsigned int positionIndex);
    };

    class WindowStandardEvents : public QObject {
        Q_OBJECT
    signals:
        void windowIsOpened();
        void windowIsClosed();
    };

    class WindowEvents : public QObject {
        Q_OBJECT
    signals:
        void alwaysOnTopStateChanged(const bool alwaysOnTop);
        void titleBarHidingStateChanged(const bool hide);
        void snappingToViewPortStateChanged(const bool snapToViewPort);
        void snappingThresholdChanged(const int snappingThreshold);
        void keepingStayingInViewPortStateChanged(const bool toBeKeptStayingInViewPort);
        void playListEditorShowingStateChanged(bool isShown);
        void minimized();
        void maximized();
        void restored();
        void hidden();
        void shown();
    };

    class SoundEvents : public QObject {
        Q_OBJECT
    signals:
        void volumeChanged(const int volume);
        void eqStateChanged(const bool activated);
        void dspStateChanged(const bool activated);
        void outputDeviceChanged(const int outputDeviceIndex);
        void soundResolutionChanged(const SoundResolution soundResolution);
    };

    class ModuleEvents : public QObject {
        Q_OBJECT
    signals:
        void amigaFilterChanged(const AmigaFilter amigaFilter);
        void interpolationFilterChanged(const InterpolationFilter interpolationFilter);
        void activeChannelAmountChanged(const size_t activeChannelAmount);
        void currentSubSongIndexChanged(const size_t currentSubSongIndex);
        void patternAmountChanged(const size_t currentPatternAmount);
        void currentPatternIndexChanged(const size_t currentPatternIndex);
        void moduleFormatChanged(const std::string songFormat);
        void channelAmountChanged(const size_t channelAmount);
        void subSongAmountChanged(const size_t subSongAmount);
    };

    class BarDisplayEvents : public QObject {
        Q_OBJECT
    signals:
        void windowFunctionChanged(const WindowFunction windowFunction);
        void barTypeChanged(const BarType barType);
        void minimumValueChanged(const int maximumValue);
        void maximumValueChanged(const int maximumValue);
        void barLedAmountChanged(const int barLedAmount);
        void ledHeightRatioChanged(const double ledRatio);
        void barWidthRatioChanged(const double barRatio);
        void dimmingRatioChanged(const double dimmingRatio);
        void dimmedTransparencyRatioChanged(const double dimmedTransparencyRatio);
        void barAmountChanged(const int barAmount);
        void gradientChanged(const QGradientStops &gradient);
        void scaleTypeChanged(const bool isLogarithmicScale);
    };

    class SettingsEvents : public QObject {
        Q_OBJECT
    signals:
        void settingsChanged();
    };

    class Events : public QObject {
        Q_OBJECT
    public:
        SongEvents songEvents;
        ScrubberEvents scrubberEvents;
        ModuleEvents moduleEvents;
        SoundEvents soundEvents;
        WindowEvents windowEvents;
        SettingsEvents settingsEvents;
        BarDisplayEvents spectrumAnalyzerEvents;
        BarDisplayEvents vuMeterEvents;
        struct {
            WindowStandardEvents playerWindowEvents;
            WindowStandardEvents playlistWindowEvents;
            WindowStandardEvents settingsWindowEvents;
            WindowStandardEvents aboutWindowEvents;
        } windowStandardEvents;
    };
}
