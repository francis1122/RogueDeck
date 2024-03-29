//
//  ForestLevelTemplate.h
//  RogueDeck
//
//  Created by Hunter Francis on 1/15/14.
//
//

#ifndef __RogueDeck__ForestLevelTemplate__
#define __RogueDeck__ForestLevelTemplate__

#include "Action.h"
#include "LLMath.h"
#include "MonsterSprite.h"
#include "LevelTemplate.h"
USING_NS_CC;


class MonsterSprite;
class ForestLevelTemplate : public LevelTemplate
{
    
public:
    virtual bool init(int _levelNumber);
    static LevelTemplate* create(){ return new ForestLevelTemplate();}
    
    virtual MonsterSprite *spawnMonster();
    
    virtual MonsterSprite *spawnBossMonster();
};


#endif /* defined(__RogueDeck__ForestLevelTemplate__) */
