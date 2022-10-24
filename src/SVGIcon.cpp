/*
SVGIcon class definitions of ModPlug Player Common Library
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "SVGIcon.hpp"

SVGIcon::SVGIcon(const QString &svgData, const QString &svgColor){
	this->svgData = svgData;
    svgDataActive = svgData;
    svgDataInactive = svgData;
	this->svgColor = svgColor;
    engineActiveIcon = new SVGIconEngine();
    engineInactiveIcon = new SVGIconEngine();
    engineActiveIcon->setSVGData(svgDataActive);
    engineInactiveIcon->setSVGData(svgDataInactive);
    activeIcon = QIcon(engineActiveIcon);
    inactiveIcon = QIcon(engineInactiveIcon);
}

void SVGIcon::setActiveColor(const RGB &color){
	this->activeColor = color;
	svgDataActive = svgData;
	svgDataActive = svgDataActive.replace(svgColor, color.hex().c_str());
    engineActiveIcon->setSVGData(svgDataActive);
}

void SVGIcon::setInactiveColor(const RGB &color){
	this->inactiveColor = color;
	svgDataInactive = svgData;
	svgDataInactive = svgDataInactive.replace(svgColor, color.hex().c_str());
    engineInactiveIcon->setSVGData(svgDataInactive);
}

const RGB SVGIcon::getActiveColor() const {
	return activeColor;
}

const RGB SVGIcon::getInactiveColor() const {
	return inactiveColor;
}

const QIcon & SVGIcon::getActiveIcon() const {
	return activeIcon;
}

const QIcon & SVGIcon::getInactiveIcon() const {
	return inactiveIcon;
}
