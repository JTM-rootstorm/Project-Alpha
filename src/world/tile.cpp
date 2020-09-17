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

#include "tile.hpp"

Tile::Tile(const unsigned int x, const unsigned int y, Terrain terrain) : terrain(std::move(terrain)) {
    resetRenderPosition(x, y);
}

void Tile::draw() {
    terrain.render();
    terrain.queueRender();
}

void Tile::resetRenderPosition(const unsigned int x, const unsigned int y) {
    terrain.setRenderPosition(x, y);
}

bool Tile::isPassable() {
    return terrain.isPassable();
}