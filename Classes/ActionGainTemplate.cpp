//
//  ActionGainTemplate.cpp
//  RogueDeck
//
//  Created by Hunter Francis on 12/10/13.
//
//

#include "ActionGainTemplate.h"
#include "Statuses.h"
#include "CardSprite.h"
#include "Targets.h"
#include "Action.h"


const std::string ActionGainTemplate::CLASS_NAME = "ActionGainTemplate";

void ActionGainTemplate::createCardTargets(CardSprite *card)
{
    CardTargets *cardTargets = new PlayAreaTargets();
    cardTargets->initWithCardSprite(card);
    createdCard->cardTargets = cardTargets;
    createdCard->setCardPicture("PictureCard");
}

#pragma mark - augmentation


void ActionGainTemplate::addNeutralAugmentationStatus(){
    
}

void ActionGainTemplate::addRedAugmentationStatus(){
    
}

void ActionGainTemplate::addBlueAugmentationStatus(){
    
}

void ActionGainTemplate::addYellowAugmentationStatus(){
    
}

void ActionGainTemplate::addGreenAugmentationStatus(){
    
}

#pragma mark - additional cost


void ActionGainTemplate::addNeutralAdditionalCost(){
}

void ActionGainTemplate::addRedAdditionalCost(){
}

void ActionGainTemplate::addBlueAdditionalCost(){
}

void ActionGainTemplate::addYellowAdditionalCost(){
}

void ActionGainTemplate::addGreenAdditionalCost(){
}


#pragma mark - main status



void ActionGainTemplate::addNeutralMainStatus(){
    
    GainActionStatus *status = new GainActionStatus();
    int actionCount = 1 + cardPower/15;
    for(int i = 0; i < actionCount; i++){
        Action *actionOne = new Action();
        actionOne->init(Blue);
        actionsGained->addObject(actionOne);
        status->initWithActionGain(actionsGained);
    }
    createdCard->cardTargets->statuses->addObject(status);
    createdCard->setCardType(Spell);
}

void ActionGainTemplate::addRedMainStatus(){
    
    GainActionStatus *status = new GainActionStatus();
    Action *actionOne = new Action();
    actionOne->init(Red);
    actionsGained->addObject(actionOne);
    Action *actionTwo = new Action();
    actionTwo->init(Red);
    actionsGained->addObject(actionTwo);
    status->initWithActionGain(actionsGained);
    createdCard->cardTargets->statuses->addObject(status);
    createdCard->setCardType(Spell);
}

void ActionGainTemplate::addBlueMainStatus(){
    

    GainActionStatus *status = new GainActionStatus();
    Action *actionOne = new Action();
    actionOne->init(Blue);
    actionsGained->addObject(actionOne);
    Action *actionTwo = new Action();
    actionTwo->init(Blue);
    actionsGained->addObject(actionTwo);
    status->initWithActionGain(actionsGained);
    createdCard->cardTargets->statuses->addObject(status);
    createdCard->setCardType(Spell);
}

void ActionGainTemplate::addYellowMainStatus(){
    
    GainActionStatus *status = new GainActionStatus();
    int actionCount = 1 + cardPower/16;
    for(int i = 0; i < actionCount; i++){
        Action *actionOne = new Action();
        actionOne->init(Neutral);
        actionsGained->addObject(actionOne);
        status->initWithActionGain(actionsGained);
    }
    createdCard->cardTargets->statuses->addObject(status);
    createdCard->setCardType(Spell);
    
    //force two discards, gain
    
}

void ActionGainTemplate::addGreenMainStatus(){
    

    GainActionStatus *status = new GainActionStatus();
    Action *actionOne = new Action();
    actionOne->init(Neutral);
    actionsGained->addObject(actionOne);
    Action *actionTwo = new Action();
    actionTwo->init(Green);
    actionsGained->addObject(actionTwo);
    status->initWithActionGain(actionsGained);
    createdCard->cardTargets->statuses->addObject(status);
    createdCard->setCardType(Spell);
}

#pragma mark -



