#ifndef __LogoLayer_SCENE_H__
#define __LogoLayer_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Adaptation.h"
#include "string.h"
#include "BaseLayer.h"
using namespace cocos2d;
using namespace ui;
using namespace std;

struct CursorItem{
	CursorItem(){
		tip = NULL;
	}
	string placeholder;
	string fontName;
	float fontSize;
	Text *tip;
	Size dsz;
};

class LogoLayer : public BaseLayer
{
public:
	LogoLayer();
	~LogoLayer();
	CREATE_FUNC(LogoLayer);
    virtual bool init();
	static ui::EditBox *AddCursorTextField(Layout *parent,int fontsz=20,bool ispass=false);
	void TouchEvent(Object *obj, TouchEventType type);
	
	void ShowYKLoginBtn(bool isshow);

	void WXLoginSend(Object *obj);
private:
	Button *m_ykloginbtn;
private:
	
};

#endif // __LogoLayer_SCENE_H__
