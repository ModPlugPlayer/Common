/*
MathUtil namespace declarations of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <cstddef>
#include <cmath>

namespace ModPlugPlayer::MathUtil {
    template <class T> T clamp(const T &value, const T &minimumValue, const T &maximumValue);
}

template<class T> T ModPlugPlayer::MathUtil::clamp(const T &value, const T &minimumValue, const T &maximumValue) {
    if(value > maximumValue)
        return maximumValue;
    if(value < minimumValue)
        return minimumValue;
    if(std::isnan(value))
        return minimumValue;
    if(std::isinf(value))
        return maximumValue;
    if(std::isinf(-value))
        return minimumValue;
    return value;
}
