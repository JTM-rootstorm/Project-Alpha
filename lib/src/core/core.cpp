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
#include <include/core/core.hpp>
#include <include/gfx/gfx.hpp>

namespace MAIN {
    Core core;
}

void Core::init() {
    if(!GFX::gfx.initGFX()){
        return;
    }

    player = std::shared_ptr<Player>(new Player(25, 22, 20));

    currentArea = std::shared_ptr<Area>(new Area("test", 90, 60));
    currentArea->genRandom(237);
    currentArea->setEntitySymbol((unsigned int) player->getWorldPosition().x,
                                 (unsigned int) player->getWorldPosition().y, &(*player));
    centerCameraAroundPlayer(true);

    //TODO: set up a location and add some areas to it; put/edit keybinds to move between areas for testing

    gameLoop();
}

void Core::gameLoop() {
    GFX::gfx.getWindow()->setActive();
    while(GFX::gfx.getWindow()->isOpen()){
        sf::Event event;
        while(GFX::gfx.getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                GFX::gfx.getWindow()->close();
            }
            else if(event.type == sf::Event::KeyPressed){
                handleInput(event.key.code);
            }
        }
        GFX::gfx.getWindow()->clear(sf::Color::Black);

        currentArea->draw();

        GFX::gfx.getWindow()->display();
    }
}

bool Core::movePlayer(int x, int y) {
    return currentArea->moveEntity((unsigned int) x, (unsigned int) y, *player);
}

void Core::handleInput(int key) {
    bool didMove = false;
    switch (key){
        case sf::Keyboard::Q: case sf::Keyboard::Escape:
            GFX::gfx.getWindow()->close();
            break;
        case sf::Keyboard::Up: case sf::Keyboard::W:
            didMove = movePlayer(player->getWorldPosition().x, player->getWorldPosition().y - 1);
            break;
        case sf::Keyboard::Right: case sf::Keyboard::D:
            didMove = movePlayer(player->getWorldPosition().x + 1, player->getWorldPosition().y);
            break;
        case sf::Keyboard::Down: case sf::Keyboard::S:
            didMove = movePlayer(player->getWorldPosition().x, player->getWorldPosition().y + 1);
            break;
        case sf::Keyboard::Left: case sf::Keyboard::A:
            didMove = movePlayer(player->getWorldPosition().x - 1, player->getWorldPosition().y);
            break;
        default:
            break;
    }
    centerCameraAroundPlayer(didMove);
}

void Core::centerCameraAroundPlayer(bool didPlayerMove) {
    if(didPlayerMove){
        GFX::gfx.centerCamera(player->getPreviousPosition(), player->getWorldPosition(), currentArea->getDimensions());
    }
}
