/*
    Project Alpha
    Copyright (C) 2017  tehguy

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>
#include <vector>

#include "../../gfx/renderable.hpp"

class Terrain : public Renderable {
public:
    enum TYPE {
        NONE,
        GRASS,
        WATER,
        MOUNTAIN,
        SNOW
    };

    Terrain(int x, int y, const sf::Rect<int> &spriteRect, TYPE type = TYPE::NONE, bool isPassable = true);

    bool isPassable() const;
    int getType() const;

private:
    bool passable;

    TYPE ttype;
};