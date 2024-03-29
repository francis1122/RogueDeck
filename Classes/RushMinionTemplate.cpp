//
//  RushMinionTemplate.cpp
//  RogueDeck
//
//  Created by Hunter Francis on 1/15/14.
//
//

#include "RushMinionTemplate.h"


#include "Statuses.h"


const std::string RushMinionTemplate::CLASS_NAME = "RushMinionTemplate";

void RushMinionTemplate::addAugmentationStatus()
{
    
}


void RushMinionTemplate::addMainStats()
{
    createdMonster->life = (int)(powerLevel/10 + LLMath::diceRoll(powerLevel/8,1));
    createdMonster->maxLife = createdMonster->life;
    createdMonster->attack = (int)(powerLevel/12 + LLMath::getIntValue(0,powerLevel/8));
    createdMonster->location = 3 + arc4random()%2;
    createdMonster->monsterLevel = (int)powerLevel;
    
    monsterSpriteName =CCString::createWithFormat("Troll");
}


void RushMinionTemplate::addRewards()
{
    //add monster rewards
    int rand = arc4random()%6;
    if(rand == 0){
        GainSoulStatus *status = new GainSoulStatus();
        status->initWithSoulGain(1);
        createdMonster->afterDeathEffectArray->addObject(status);
        rewardDescription = CCString::createWithFormat("Gain 1 Soul");
        
    }else if(rand ==1){
        GainActionStatus *status = new GainActionStatus();
        CCArray *actions = new CCArray();
        actions->init();
        Action *action = new Action();
        action->init(Neutral);
        actions->addObject(action);
        status->initWithActionGain(actions);
        createdMonster->afterDeathEffectArray->addObject(status);
        rewardDescription = CCString::createWithFormat("Gain an Action");
    }
    
}
