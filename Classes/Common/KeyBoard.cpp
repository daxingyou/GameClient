#include "KeyBoard.h"
#include "TipLayer.h"
#include "GameControl.h"
#include "LoginLayer.h"


KeyLayer::KeyLayer(){
	//���ֻ����ؼ��ļ��� 
	auto listener = EventListenerKeyboard::create();
	//�ͻص������� 
	listener->onKeyPressed = CC_CALLBACK_2(KeyLayer::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(KeyLayer::onKeyReleased, this);
	//��ӵ��¼��ַ����� 
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

KeyLayer::~KeyLayer(){
	if (KeyBoard::getIns()->getKeyLayer() == this){
		KeyBoard::getIns()->setKeyLayer(NULL);
	}
}

KeyLayer *KeyLayer::create(KEYTYPE type){
	KeyLayer *pRet = new KeyLayer();
	if (pRet&&pRet->init(type)){
		pRet->autorelease();
	}
	else{
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool KeyLayer::init(KEYTYPE type){
	if (!Layer::init()){
		return false;
	}
	m_type = type;
	return true;
}

void KeyLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
	log("press:%c", keyCode);
}

void KeyLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event){
	log("end:%c", keyCode);
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK){
		GameControl *p = GameControl::getIns();
		TipLayer *tip = p->getTipLayer();
		if (tip){
			tip->removeFromParentAndCleanup(true);
		}
		else{
			tip = TipLayer::create();
			this->addChild(tip);
			if (m_type == EXIT_KEYTYPE){
				tip->setContent(XXIconv::GBK2UTF("�Ƿ�ȷ��Ҫ�˳���Ϸ?"));
			}
			else if (m_type == BACK_KEYTYPE){
				tip->setContent(XXIconv::GBK2UTF("�Ƿ�ȷ������?"));
			}
		}
	}
}




















KeyBoard *KeyBoard::m_ins = NULL;

KeyBoard::KeyBoard(){
	m_pKeyLayer = NULL;
	m_isMainback = false;
}

KeyBoard::~KeyBoard(){
	m_ins = NULL;
}

bool KeyBoard::init(){
	
	return true;
}

KeyBoard* KeyBoard::getIns(){
	if (!m_ins){
		m_ins = new KeyBoard();
		m_ins->init();
	}
	return m_ins;
}

void KeyBoard::setKetPad(KEYTYPE type,Node *parent){
	if (!m_pKeyLayer){
		m_pKeyLayer = KeyLayer::create(type);
		m_pKeyLayer->retain();
	}
	else{
		m_pKeyLayer->removeFromParent();
	}
	if (m_pKeyLayer&&!m_pKeyLayer->getParent()){
		m_pKeyLayer->setKeyType(type);
		parent->addChild(m_pKeyLayer,2000);
	}
}