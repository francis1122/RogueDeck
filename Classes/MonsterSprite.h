//
//  MonsterSprite.h
//  RogueDeck
//
//  Created by Hunter Francis on 11/20/13.
//
//

#ifndef __RogueDeck__MonsterSprite__
#define __RogueDeck__MonsterSprite__

#include "cocos2d.h"
#include "BaseObject.h"


class MonsterSprite : public BaseObject
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static node()" method manually
    CREATE_FUNC(MonsterSprite);
    
    cocos2d::CCLabelTTF *lifeLabel;
    
    cocos2d::CCRenderTexture *lifeRender;
    cocos2d::CCRenderTexture *attackRender;
    cocos2d::CCLabelTTF *attackLabel;
    
    cocos2d::CCLabelTTF *detailsLabel;
    
    cocos2d::CCSprite *glowSprite;
    
    //monster variables
    int life;
    int maxLife;
    int attack;
    int default_attack;
    int location;
    int lane;
    bool hasTaunt;
    bool hasRange;
    float monsterLevel;
    bool isDead;
    bool isBoss;
    
    //given to a monster on there first turn so they don't attack or move or have any fun
    bool summoningSickness;
    
    void updateInterface();
    void turnUpdate();
    void onDeath();
    
    //effects that happen when the monster dies
    cocos2d::CCArray *afterDeathEffectArray;
    
    //effects that get added on attack, this array is cleared at the end of each attack
    cocos2d::CCArray *killingBlowArray;
    cocos2d::CCArray *activeStatusArray;
    
    
    void enableInteractive();
    void disableInteractive();
    
    void setupMonsterImage(cocos2d::CCString* monserSpriteName);
    
    void changeMonsterAttack(int attackOffset);
    void changeMonsterHealth(int healthOffset);
    virtual void doDamage();
    
private:
    
};

#endif /* defined(__RogueDeck__MonsterSprite__) */
