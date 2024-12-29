/*
EventFilters class declarations of ModPlug Player
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <QObject>
#include <QEvent>
#include <QPoint>
#include <QMainWindow>

namespace ModPlugPlayer::EventFilters {
    class MoveByMouseClickEventFilter : public QObject
    {
        Q_OBJECT
        public:
            MoveByMouseClickEventFilter(QMainWindow *mainWindow);
            bool eventFilter(QObject *watched, QEvent *event);
            bool getSnapToViewPort() const;
            void setSnapToViewPort(bool snapToViewPort);
            int getSnappingThreshold() const;
            void setSnappingThreshold(int snappingThreshold);
            bool getKeepStayingInViewPort() const;
            void setKeepStayingInViewPort(bool keepStayingInViewPort);

        private:
            QMainWindow *mainWindow;
            QPoint dragPosition;
            QPoint lastPosition;
            int snappingThreshold = 35;
            bool snapToViewPort = true;
            bool keepStayingInViewPort = true;
    };

    class KeepFixedSizeEventFilter : public QObject
    {
        Q_OBJECT
        public:
            bool eventFilter(QObject *watched, QEvent *event);
        private:
            QMainWindow *mainWindow;
    };

    class ScrollBarVisibilityEventFilter : public QObject
    {
        Q_OBJECT
    public:
        bool eventFilter(QObject *scrollBar, QEvent *event);
        template <typename Func> void setSignal(const typename QtPrivate::FunctionPointer<Func>::Object *sender, Func signal);
    signals:
        void scrollBarVisibilityChanged(bool visible);
    private:
        QWidget *widget;
    };

    class MouseWheelEventFilter : public QObject
    {
        Q_OBJECT
    public:
        bool eventFilter(QObject *watched, QEvent *event);
        template <typename Func> void setSignal(const typename QtPrivate::FunctionPointer<Func>::Object *sender, Func signal);
    signals:
        void mouseWheelEvent(QPoint angleDelta, bool inverted);
    private:
        QWidget *widget;
    };
}

template<typename Func>
void ModPlugPlayer::EventFilters::ScrollBarVisibilityEventFilter::setSignal(const QtPrivate::FunctionPointer<Func>::Object *sender, Func signal) {
    connect(this, &ScrollBarVisibilityEventFilter::scrollBarVisibilityChanged, sender, signal);
}

template<typename Func>
void ModPlugPlayer::EventFilters::MouseWheelEventFilter::setSignal(const QtPrivate::FunctionPointer<Func>::Object *sender, Func signal) {
    connect(this, &MouseWheelEventFilter::mouseWheelEvent, sender, signal);
}
