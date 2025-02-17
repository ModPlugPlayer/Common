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
#include "MessageCenter/MessageCenterRequests.hpp"
#include "MessageCenter/MessageCenterEvents.hpp"

using namespace ModPlugPlayer::MessageCenterRequests;
using namespace ModPlugPlayer::MessageCenterEvents;

namespace ModPlugPlayer {
    class MessageCenter : public QObject {
        Q_OBJECT
    public:
        MessageCenter(MessageCenter const &) = delete;
        void operator =(MessageCenter const &) = delete;
        static MessageCenter& getInstance();
        Requests requests;
        Events events;
    private:
        MessageCenter();
        static std::mutex mutex;
    };
}
