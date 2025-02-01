/*
VectorUtil class declarations of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace VectorUtil {
    template<class T> int findIndexOfElement(const std::vector<T> &list, const T &element);
    template<class T> bool elementExists(const std::vector<T> &list, const T &element);
    template <typename T> void eraseElementFromVector(std::vector<T> &myVector, const T &value);
}

template<class T> int VectorUtil::findIndexOfElement(const std::vector<T> &list, const T &element) {
    auto it = std::find(list.begin(), list.end(), element);
    ptrdiff_t dist;
    if (it == list.end())
    {
        return -1;
    } else
    {
        dist = std::distance(list.begin(), it);
    }
    return int(dist);
}

template<class T>
bool VectorUtil::elementExists(const std::vector<T> &list, const T &element)
{
    if(std::find(list.begin(), list.end(), element)!=list.end())
        return true;
    return false;
}

template <typename T>
void VectorUtil::eraseElementFromVector(std::vector<T> &elements, const T &value){
    elements.erase(std::remove(elements.begin(), elements.end(), value), elements.end());
}
