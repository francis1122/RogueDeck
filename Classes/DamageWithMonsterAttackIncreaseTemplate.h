//
//  DamageWithMonsterAttackIncreaseStatus.h
//  RogueDeck
//
//  Created by Hunter Francis on 2/25/14.
//
//

#ifndef __RogueDeck__DamageWithMonsterAttackIncreaseTemplate__
#define __RogueDeck__DamageWithMonsterAttackIncreaseTemplate__

#include "cocos2d.h"
#include "CardTemplate.h"
USING_NS_CC;

class CardSprite;
class DamageWithMonsterAttackIncreaseTemplate : public CardTemplate
{
    
public:
    static const std::string CLASS_NAME;
    static CardTemplate* create(){ return new DamageWithMonsterAttackIncreaseTemplate();}
    
    virtual void createCardTargets(CardSprite *card);
    
    virtual void addNeutralAugmentationStatus();
    virtual void addRedAugmentationStatus();
    virtual void addBlueAugmentationStatus();
    virtual void addYellowAugmentationStatus();
    virtual void addGreenAugmentationStatus();
    
    virtual void addNeutralAdditionalCost();
    virtual void addRedAdditionalCost();
    virtual void addBlueAdditionalCost();
    virtual void addYellowAdditionalCost();
    virtual void addGreenAdditionalCost();
    
    virtual void addNeutralMainStatus();
    virtual void addRedMainStatus();
    virtual void addBlueMainStatus();
    virtual void addYellowMainStatus();
    virtual void addGreenMainStatus();
    
};

#endif /* defined(__RogueDeck__DamageWithMonsterAttackIncreaseTemplate__) */
