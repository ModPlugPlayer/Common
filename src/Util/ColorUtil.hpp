/*
ColorUtil namespace declarations of ModPlug Player
Copyright (C) 2025 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <cstddef>
#include <cmath>
#include <RGB.hpp>

namespace ModPlugPlayer::ColorUtil {
    static inline double calculatePerceptualLightness(const RGB &rgb);
    static inline double calculateContrast(const RGB &rgb1, const RGB &rgb2);
    /**
     * Calculates black or white foreground color that makes maximum contrast for the given background color.
     * @param backgroundColor background color
     * @param tolerence Tolorence value between 0 and 100 for white color. For example, is 10 is chosen for tolerence,
     * then until contrast is 10, this method will return true, otherwise, will return the calculated value.
     * @return false for black, true for white.
     */
    static inline bool calculateBWForegroundColor(const RGB & backgroundColor, const int &tolerence);
}

inline double ModPlugPlayer::ColorUtil::calculatePerceptualLightness(const RGB & rgb) {
    //Convert all sRGB 8 bit integer values to decimal 0.0-1.0
    double vR = double(rgb.red) / 255.0;
    double vG = double(rgb.green) / 255.0;
    double vB = double(rgb.blue) / 255.0;
    auto sRGBtoLin = [](double colorChannel) {
        // Send this function a decimal sRGB gamma encoded color value
        // between 0.0 and 1.0, and it returns a linearized value.

        if ( colorChannel <= 0.04045 ) {
            return colorChannel / 12.92;
        } else {
            return pow((( colorChannel + 0.055)/1.055),2.4);
        }
    };

    double Y = (0.2126 * sRGBtoLin(vR) + 0.7152 * sRGBtoLin(vG) + 0.0722 * sRGBtoLin(vB));

    auto YtoLstar = [](double Y) {
        // Send this function a luminance value between 0.0 and 1.0,
        // and it returns L* which is "perceptual lightness"

        if ( Y <= (216.0/24389.0) ){       // The CIE standard states 0.008856 but 216/24389 is the intent for 0.008856451679036
            return Y * (24389/27);  // The CIE standard states 903.3, but 24389/27 is the intent, making 903.296296296296296
        } else {
            return pow(Y,(1.0/3.0)) * 116.0 - 16.0;
        }
    };

    return YtoLstar(Y);
}

inline double ModPlugPlayer::ColorUtil::calculateContrast(const RGB &rgb1, const RGB &rgb2) {
    double lum1 = calculatePerceptualLightness(rgb1);
    double lum2 = calculatePerceptualLightness(rgb2);
    double brightest = std::max(lum1, lum2);
    double darkest = std::min(lum1, lum2);
    return brightest - darkest;
}

inline bool ModPlugPlayer::ColorUtil::calculateBWForegroundColor(const RGB &backgroundColor, const int &tolerence) {
    RGB black, white;
    black.red = 0;
    black.green = 0;
    black.blue = 0;
    white.red = 255;
    white.green = 255;
    white.blue = 255;
    double contrastWithWhite = calculateContrast(backgroundColor, white);
    double contrastWithBlack = calculateContrast(backgroundColor, black);
    if(std::abs(contrastWithWhite - contrastWithBlack) <= tolerence)
        return true;
    if(contrastWithWhite < contrastWithBlack)
        return false;
    else
        return true;
}
