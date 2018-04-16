#ifndef __APPMACROS_H__
#define __APPMACROS_H__

#include "cocos2d.h"
#include "ccEvent.h"
#include "MD55.h"
#include "XXIconv.h"
#include "Hall.h"
#include <string.h>
#include "ConfigProto.h"
//design screen size



static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(852, 480);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1280, 720);
//Screen Size
#define SCREEN_SIZE cocos2d::CCDirector::sharedDirector()->getVisibleSize();

//Resource Scale
#define RESOURCE_SCALE	((CCDirector::sharedDirector()->getVisibleSize().width/designResolutionSize.width) > (CCDirector::sharedDirector()->getVisibleSize().height/designResolutionSize.height) ?\
						 (CCDirector::sharedDirector()->getVisibleSize().width/designResolutionSize.width) : (CCDirector::sharedDirector()->getVisibleSize().height/designResolutionSize.height))

#define RESOURCE_SCALEX (CCDirector::sharedDirector()->getVisibleSize().width/designResolutionSize.width)

#define RESOURCE_SCALEY (CCDirector::sharedDirector()->getVisibleSize().height/designResolutionSize.height)


#define FONTS1 "fonts/yahei.ttf"
#define  FONTS2 "fonts/STXingkai.ttf"
//#define sqlhttp "http://192.168.50.151:8080/"
#define sqlhttp "http://www.lesharecs.com:8080/"
#define DECKEY "FQ6M1w0GswdKkTuZWcFmM1rU3bDB/CTiw+KrONdCPOg"

using namespace cocos2d;
using namespace std;
using namespace protocol;
using namespace ::google::protobuf;
USING_NS_XX;
//static string g_version = cocos2d::cocos2dVersion();

/************************************************************************/
/* ��ͷ                                                                 */
/************************************************************************/
typedef struct _Head
{
	char _req[3];//���������к�
	char _stamp;
	char _bodylen[2];//����
	char _cmd[4];//cmd
}Head, *PHead;

#define HEADLEN sizeof(_Head)
#define REPLACESTRR "||||&***#@"
#define REPLACESTRN "%^&*():"

typedef void (Ref::*EventHandler)(ccEvent*);
#define Event_Handler(_SELECTOR)(EventHandler)(&_SELECTOR)

#endif /* __APPMACROS_H__ */

/******NOTICE******/
#define NOTICE_WXLOGIN "wxlogin"
