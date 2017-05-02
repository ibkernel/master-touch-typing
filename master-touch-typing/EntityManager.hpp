//
//  EntityManager.hpp
//  master-touch-typing
//
//  Created by Wayne Chang on 2017/5/2.
//  Copyright © 2017年 WayneChang. All rights reserved.
//

#ifndef EntityManager_hpp
#define EntityManager_hpp
#include <unordered_map>
#include <functional>
#include "Enemy.hpp"
#include "Player.hpp"

struct EnumClassHash2
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

using EntityContainer = std::unordered_map<unsigned int,EntityBase*>;
using EntityFactory = std::unordered_map<EntityType, std::function<EntityBase*(void)>, EnumClassHash2>;
using EnemyTypes = std::unordered_map<std::string,std::string>;

struct SharedContext;

class EntityManager{
public:
    EntityManager(SharedContext* l_context, unsigned int l_maxEntities);
    ~EntityManager();
    
    int Add(const EntityType& l_type, const std::string& l_name = "");
    EntityBase* Find(unsigned int l_id);
    EntityBase* Find(const std::string& l_name);
    void Remove(unsigned int l_id);
    
    void Update(float l_dT);
    void Draw();
    
    void Purge();
    
    SharedContext* GetContext();
private:
    template<class T>
    void RegisterEntity(const EntityType& l_type){
        m_entityFactory[l_type] = [this]() -> EntityBase*
        {
            return new T(this);
        };
    }
    
    void ProcessRemovals();
    void LoadEnemyTypes(const std::string& l_names);
    void EntityCollisionCheck();
    
    EntityContainer m_entities;
    EnemyTypes m_enemyTypes;
    EntityFactory m_entityFactory;
    SharedContext* m_context;
    unsigned int m_idCounter;
    unsigned int m_maxEntities;
    
    std::vector<unsigned int> m_entitiesToRemove;
};

#endif /* EntityManager_hpp */
