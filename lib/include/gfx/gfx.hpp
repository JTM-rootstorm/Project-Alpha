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
#include <SFML/Graphics.hpp>
#include <vector>

class Graphics {
public:
    Graphics();

    bool checkCollision(sf::Rect<int> a, sf::Rect<int> b);
    bool checkWithinCamera(sf::Rect<int> object);

    bool initGFX();
    bool loadSpriteSheet();

    const std::shared_ptr<sf::RenderWindow>& getWindow();
    const sf::Sprite createSprite(unsigned int clipIndex);

    void moveCamera(sf::Vector2f& offset);

    sf::Rect<int> actualCameraBounds;

private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::View camera;
    sf::Texture tileTexture;
    std::vector<sf::Rect<int>> textureRects;
};

namespace GFX {
    extern Graphics gfx;
}