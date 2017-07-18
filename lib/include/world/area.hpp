/*
    CPPAdventures
    Copyright (C) 2017  TehGuy

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

#include <memory>
#include <string>
#include <vector>

#include <include/entity/player.hpp>
#include <include/item/item.hpp>
#include <include/world/terrain/terrain.hpp>

class Area {
public:
    Area(std::string id, unsigned int _width, unsigned int _height);
    ~Area();

    const std::string& getIdentifier();

    sf::Vector2i getDimensions();

    void setMapSymbol(unsigned int x, unsigned int y, Terrain* terrain);
    void setItemSymbol(unsigned int x, unsigned int y, Item *item);
    void setEntitySymbol(unsigned int x, unsigned int y, Entity* entity);
    bool moveEntity(unsigned int x, unsigned int y, Entity& entity);

    const CORE::SYMBOL getMapSymbol(unsigned int row, unsigned int col);
    const CORE::SYMBOL getItemSymbol(unsigned int x, unsigned int y);
    const CORE::SYMBOL getEntitySymbol(unsigned int row, unsigned int col);

    void unlinkAreas();

    void setAreaNorth(Area& area);
    void setAreaEast(Area& area);
    void setAreaSouth(Area& area);
    void setAreaWest(Area& area);

    std::shared_ptr<Area>& getAreaNorth();
    std::shared_ptr<Area>& getAreaEast();
    std::shared_ptr<Area>& getAreaSouth();
    std::shared_ptr<Area>& getAreaWest();

    void draw();
    void genRandom(const unsigned int& seed);
private:

    std::string identifier;

    //unsigned int width, height;
    sf::Vector2i dimensions;

    std::vector<std::vector<Terrain*>> map;
    std::vector<std::vector<Item*>> itemLayer;
    std::vector<std::vector<Entity*>> entityLayer;

    std::shared_ptr<Area> areaNorth;
    std::shared_ptr<Area> areaEast;
    std::shared_ptr<Area> areaSouth;
    std::shared_ptr<Area> areaWest;
};