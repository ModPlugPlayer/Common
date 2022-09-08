/*
LedButton class definitions of ModPlug Player Common Library
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "LEDColorProperties.hpp"

void LEDColorProperties::setActiveLEDColor(const RGB & color) {
    activeLEDColor = color;
    refreshStyleSheet();
}

void LEDColorProperties::setInactiveLEDColor(const RGB & color) {
    inactiveLEDColor = color;
    refreshStyleSheet();
}

RGB LEDColorProperties::getActiveLEDColor() const {
    return activeLEDColor;
}

RGB LEDColorProperties::getInactiveLEDColor() const {
    return inactiveLEDColor;
}

const RGB &LEDColorProperties::getLEDBorderColor() const
{
    return ledBorderColor;
}

void LEDColorProperties::setLEDBorderColor(const RGB &ledBorderColor)
{
    this->ledBorderColor = ledBorderColor;
}
