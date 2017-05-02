//
//  Game.hpp
//  master-touch-typing
//
//  Created by Wayne Chang on 2017/4/26.
//  Copyright © 2017年 WayneChang. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "Window.hpp"
#include "EventManager.hpp"
#include "StateManager.hpp"
#include "TextureManager.hpp"
#include "EntityManager.hpp"

class Game{
public:
    Game();
    ~Game();
    
    void Update();
    void Render();
    void LateUpdate();
    
    sf::Time GetElapsed();
    
    Window* GetWindow();
private:
    SharedContext m_context;
    Window m_window;
    StateManager m_stateManager;
    EntityManager m_entityManager;
    TextureManager m_textureManager;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    void RestartClock();
};

#endif /* Game_hpp */
