//
//  AnimationManager.cpp
//  RogueDeck
//
//  Created by Hunter Francis on 1/7/14.
//
//

#include "AnimationManager.h"


#include "MonsterGenerator.h"
#include "MonsterSprite.h"
#include "Statuses.h"
#include "Action.h"
#include "LLMath.h"
#include "BaseObject.h"
#include "AnimationObject.h"
#include "Constants.h"
#include "GameManager.h"

using namespace cocos2d;

//All static variables need to be defined in the .cpp file
//I've added this following line to fix the problem
AnimationManager* AnimationManager::m_mySingleton = NULL;

AnimationManager::AnimationManager()
{
    this->animationQueue = new CCArray();
    this->animationQueue->init();
    animationInProgress = false;
}

AnimationManager* AnimationManager::sharedAnimationManager()
{
    //If the singleton has no instance yet, create one
    if(NULL == m_mySingleton)
    {
        //Create an instance to the singleton
        m_mySingleton = new AnimationManager();
        m_mySingleton->init();
    }
    
    //Return the singleton object
    return m_mySingleton;
}

void AnimationManager::resetAnimationManager()
{
    this->removeFromParentAndCleanup(true);
    animationInProgress = false;
    animationQueue->removeAllObjects();
}


void AnimationManager::addAnimation(AnimationObject *object){
    this->animationQueue->addObject(object);
    if(!animationInProgress){
        this->updateAnimations();
    }
}

void AnimationManager::updateAnimations(){
    //run the next animation in the queue
    if(this->animationQueue->count() >= 1){
        AnimationObject *animation = (AnimationObject*)animationQueue->objectAtIndex(0);
        this->runAnimation(animation);
        float duration;
        if(animation->isArray || duration > 0.0){
            duration = animation->duration;
        }else{
            duration = animation->getAction()->getDuration();
        }
        animationQueue->removeObjectAtIndex(0);
        animationInProgress = true;
        
        //setup callback for when animation finishes
        CCDelayTime *delay = CCDelayTime::create(duration);
        CCCallFunc *func = CCCallFunc::create(this, SEL_CallFunc(&AnimationManager::updateAnimations));
        CCSequence *seq = CCSequence::createWithTwoActions(delay, func);
        this->runAction(seq);

        CCLog("animation");
    }else{
        CCLog("no animation");
        animationInProgress = false;
        GM->isInteractive = true;
    }
}

void AnimationManager::runAnimation(AnimationObject *animation){
    if(animation->isArray){
        CCArray *array = animation->animationArray;
        for(int i = 0; i < array->count(); i++){
            AnimationObject *nextObject = (AnimationObject*)array->objectAtIndex(i);
            this->runAnimation(nextObject);
        }
    }else{
        animation->getObject()->stopAllActions();
        animation->getObject()->runAction(animation->getAction());
    }

}
/*
#pragma mark - helper functions

void AnimationManager::addCard(CCNode *node)
{
    GM->gameLayer->addChild(node, 10000);
}

void AnimationManager::removeCard(CCNode *node)
{
    node->removeFromParentAndCleanup(true);
}
*/
