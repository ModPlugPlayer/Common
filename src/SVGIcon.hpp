/*
SVGIcon class declarations of ModPlug Player Common Library
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <QString>
#include "SVGIconEngine.hpp"
#include <RGB.hpp>
#include <QIcon>
#include <QObject>

class SVGIcon : public QObject
{
	Q_OBJECT
	public:
		SVGIcon(const QString &svgData, const QString &svgColor);
		void setActiveColor(const RGB &color);
		void setInactiveColor(const RGB &color);
        const RGB getActiveColor() const;
        const RGB getInactiveColor() const;
        const QIcon & getActiveIcon() const;
        const QIcon & getInactiveIcon() const;
	private:
		QString svgData, svgDataActive, svgDataInactive, svgColor;
		RGB activeColor, inactiveColor;
        QIcon activeIcon, inactiveIcon;
        SVGIconEngine *engineInactiveIcon, *engineActiveIcon; //Don't delete engines, they are deleted by QIcons
};
