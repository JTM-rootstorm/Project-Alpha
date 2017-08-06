/*
    Project Alpha
    Copyright (C) 2017  Pixima Development

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

#include <include/enums/enums.hpp>
#include <include/entity/cursor.hpp>
#include <include/world/area.hpp>

class MArea {
public:
    MArea(std::string name);
    ~MArea();

    void spawnCursor(int x, int y);

    bool moveCursor(int xOffset, int yOffset);
    bool moveCursorToThisArea(int xOffset, int yOffset, const std::shared_ptr<MArea> &prevArea);

    void despawnCursor();
    Cursor passCursor();

    void draw();

    const std::shared_ptr<Cursor>& getCursor();

    void createTileAtCursor(ENUMS::TTYPE ttype);

    const std::shared_ptr<Area> & getHeldArea();

    sf::Vector2i getDimensions();
private:
    void setCursorMap(int x, int y, const std::shared_ptr<Cursor> set);

    std::shared_ptr<Cursor> cursor;

    std::vector<std::vector<std::shared_ptr<Cursor>>> cursorMap;

    std::shared_ptr<Area> heldArea;
};