/*
LedButton class definitions of ModPlug Player Common Library
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "SVGLEDButton.hpp"

SVGLEDButton::SVGLEDButton(QWidget *parent){
    setParent(parent);
    connect(this, &SVGLEDButton::pressed, this, &SVGLEDButton::pressed);
    connect(this, &SVGLEDButton::released, this, &SVGLEDButton::released);
}

void SVGLEDButton::setSVGIcon(SVGIcon *svgIcon) {
    this->svgIcon = svgIcon;
}

void SVGLEDButton::setLocked(bool lock)
{
    locked = lock;
    setIcon(locked ? svgIcon->getInactiveIcon() : svgIcon->getActiveIcon());
}

void SVGLEDButton::lock() {
    locked = true;
    setIcon(svgIcon->getActiveIcon());
}

void SVGLEDButton::unlock()
{
    locked = false;
}

bool SVGLEDButton::isLocked() {
    return locked;
}

SVGIcon *SVGLEDButton::getSVGIcon() const {
    return svgIcon;
}

void SVGLEDButton::refreshStyleSheet()
{

}

void SVGLEDButton::pressed() {
    setIcon(svgIcon->getActiveIcon());
}

void SVGLEDButton::released() {
    setIcon(locked ? svgIcon->getInactiveIcon() : svgIcon->getActiveIcon());
}
