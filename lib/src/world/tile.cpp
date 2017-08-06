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

#include <include/world/tile.hpp>

Tile::Tile() {

}

void Tile::setTerrain(const std::shared_ptr<Terrain> terrainToPlace) {
    terrain = terrainToPlace;
}

const std::shared_ptr<Terrain> &Tile::getTerrain() {
    return terrain;
}

void Tile::setEntityHere(const std::shared_ptr<Entity> entityToAdd) {
    entityHere = entityToAdd;
}

void Tile::removeEntityHere() {
    entityHere = nullptr;
}

void Tile::draw() {
    if(entityHere != nullptr){
        entityHere->render();
    }
    else if(terrain != nullptr){
        terrain->render();
    }
}

void Tile::resetRenderPosition(int x, int y) {
    if(terrain != nullptr){
        terrain->setRenderPosition(x, y);
    }
}

bool Tile::isPassable() {
    if(terrain != nullptr && entityHere == nullptr){
        return terrain->isPassable();
    }

    return false;
}
