/*
LedButton class declarations of ModPlug Player Common Library
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include "LEDColorProperties.hpp"
#include "TextColorProperties.hpp"
#include "SVGIcon.hpp"
#include <QPushButton>

class SVGLEDButton : public QPushButton, public LEDColorProperties, public TextColorProperties {
    Q_OBJECT
public:
    SVGLEDButton(QWidget *parent = nullptr);
    void setSVGIcon(SVGIcon * svgIcon);
    void setLocked(bool lock);
    void lock();
    void unlock();
    bool isLocked();
    SVGIcon * getSVGIcon() const;
protected:
    SVGIcon * svgIcon = nullptr;
    bool locked = false;
    void refreshStyleSheet() override;
protected slots:
    void pressed();
    void released();
};
