//
//  BaseState.hpp
//  master-touch-typing
//
//  Created by Wayne Chang on 2017/4/27.
//  Copyright © 2017年 WayneChang. All rights reserved.
//

#ifndef BaseState_hpp
#define BaseState_hpp

#include <SFML/Graphics.hpp>

class StateManager; //forward declaration

class BaseState{
    friend class StateManager;
public:
    BaseState(StateManager* l_stateManager)
    :m_stateMgr(l_stateManager),m_transparent(false),
    m_transcendent(false){}
    virtual ~BaseState(){}
    
    virtual void OnCreate() = 0;    //pushed into stack
    virtual void OnDestroy() = 0;   //removed from stack
    
    virtual void Activate() = 0;    //moved to the top
    virtual void Deactivate() = 0;  //removed from top
    
    virtual void Update(const sf::Time& l_time) = 0;
    virtual void Draw() = 0;
    
    void SetTransparent(const bool& l_transparent){
        m_transparent = l_transparent;
    }
    bool IsTransparent()const{ return m_transparent; }
    void SetTranscendent(const bool& l_transcendence){
        m_transcendent = l_transcendence;
    }
    bool IsTranscendent()const{ return m_transcendent; }
    StateManager* GetStateManager(){ return m_stateMgr; }
protected:
    StateManager* m_stateMgr;
    
    
    bool m_transparent; // if render (?
    bool m_transcendent;// is superior
};

#endif /* BaseState_hpp */