/*
TextButton class definitions of ModPlug Player Common Library
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "TextButton.hpp"

void TextButton::setBackgroundColor(const RGB & color) {
    backgroundColor = color;
}

void TextButton::setTextColor(const RGB & color) {
    textColor = color;
}

RGB TextButton::getBackgroundColor() const {
    return backgroundColor;
}

RGB TextButton::getTextColor() const {
    return textColor;
}

const QString & TextButton::getStyleSheetTemplate() const {
    return styleSheetTemplate;
}

void TextButton::setStyleSheetTemplate(const QString & styleSheetTemplate) {
    this->styleSheetTemplate = styleSheetTemplate;
}
