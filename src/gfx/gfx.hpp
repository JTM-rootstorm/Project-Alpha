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

#include <memory>
#include <vector>

#include "../core/constants.hpp"

class Graphics {
public:
    static Graphics& Instance() {
        static Graphics instance;
        return instance;
    };

    Graphics(Graphics const&) = delete;
    void operator=(Graphics const&) = delete;


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
    bool initGFX(const std::string &tileTexturePath, const std::string &windowName,
                 unsigned int screenWidth = CONSTANTS::GET_OBJECT().SCREEN_WIDTH,
                 unsigned int screenHeight = CONSTANTS::GET_OBJECT().SCREEN_HEIGHT, unsigned int framerate = 60);
#pragma clang diagnostic pop

    sf::Sprite createSprite(sf::Rect<int> &spriteRect) const;

    void draw(const sf::Drawable& drawable, const sf::Rect<int> &object,
              const sf::RenderStates& states = sf::RenderStates::Default);
    void centerCamera(const sf::Vector2i &prevPos, const sf::Vector2i &currentPos);
    void forceCenterCamera(const sf::Vector2i &posToCenterOn);

private:
    Graphics() = default;

    bool checkWithinCamera(const sf::Rect<int> &object) const;
    bool loadSpriteSheet(const std::string& filePath);
    bool checkCollision(const sf::Rect<int>& a, const sf::Rect<int>& b) const;

    void initCamera(int w, int h);
    void moveCamera(const sf::Vector2f &offset);

    sf::RenderWindow window;
    sf::View camera;
    sf::Texture tileTexture;

    sf::Rect<int> actualCameraBounds;
};