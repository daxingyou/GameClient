﻿#include "GameControl.h"



GameControl *GameControl::m_ins=NULL;

GameControl::GameControl(){
	m_pLoginLayer = NULL;
	m_pMainLayer = NULL;
	m_pUserInfoLayer = NULL;
	m_pSetLayer = NULL;
	m_pShopLayer = NULL;
	m_pSignLayer = NULL;
	m_pFriendLayer = NULL;
	m_pFankuiLayer = NULL;
	m_pFreeLayer = NULL;
	m_pExchangeLayer = NULL;
	m_pTaskLayer = NULL;
	m_pMailLayer = NULL;
	m_pActiveLayer = NULL;
	m_pFirstChargeLayer = NULL;
	m_pAboutLayer = NULL;
	m_pHelpLayer = NULL;
	m_pChatLayer = NULL;
	m_pMailTipLayer = NULL;
	m_pRewardTipLayer = NULL;
	m_pLoadingLayer = NULL;
	m_pCreateRoomLayer = NULL;
	m_pJoinRoomLayer = NULL;
	m_pMJGameLayer = NULL;
	m_pGameUI = NULL;
	m_pMJGameScene = NULL;
	Director::sharedDirector()->getScheduler()->scheduleUpdate(this, 1, false);
}

GameControl::~GameControl(){
	Director::sharedDirector()->getScheduler()->unscheduleUpdate(this);
}

bool GameControl::init()
{
	
    return true;
}

GameControl* GameControl::getIns(){
	if (!m_ins){
		m_ins = new GameControl();
		m_ins->init();
	}
	return m_ins;
}

void GameControl::replaceScene(Scene *scene){
	Director *p = Director::sharedDirector();
	CCTransitionFade *reScene = CCTransitionFade::create(0.3, scene);
	p->replaceScene(reScene);
}

void GameControl::PushLaBa(string content, int times){
	LaBaItem *item = new LaBaItem();
	item->_content = content;
	item->_times = times;
	m_contents.push_back(item);
}

void GameControl::update(float dt){
	if (m_pMainLayer&&m_pMainLayer->isFinished() && !m_contents.empty()){
		vector<LaBaItem *>::iterator itr = m_contents.begin();
		for (itr; itr != m_contents.end();itr++){
			LaBaItem *item = *itr;
			string content = item->_content;
			int times = item->_times;
			if (m_contents.size() == 1&&times==-1){
				if (m_pMainLayer){
					m_pMainLayer->ShowLaBa(content);
				}
				break;
			}
			else if(times!=-1){
				if (m_pMainLayer){
					m_pMainLayer->ShowLaBa(content);
					times -= 1;
					item->_times = times;
					if (times <= 0){
						delete item;
						m_contents.erase(itr);
					}
				}
				break;
			}
		}
	}
}