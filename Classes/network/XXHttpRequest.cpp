﻿#include "XXHttpRequest.h"
#include "MD55.h"
#include "YMSocketDataEvent.h"
#include "HttpInfo.h"

XXHttpRequest* XXHttpRequest::m_ins=NULL;
bool XXHttpRequest::m_init=false;

XXHttpRequest::XXHttpRequest()
{
	
}

XXHttpRequest::~XXHttpRequest()
{
	
}

bool XXHttpRequest::init()
{
	
	return true;
}

XXHttpRequest* XXHttpRequest::getIns(){
	if(!m_init){
		m_ins=new XXHttpRequest();
		m_init=true;
		m_ins->init();
	}
	return m_ins;
}

void XXHttpRequest::postServerDataFromUrl(string url, YMSocketData sd, SEL_HttpResponse respond){
	CCLOG("%s", url.c_str());
	HttpRequest* request = new HttpRequest();
	//设置网络请求地址
	//string url=GameControl::getIns()->getHttpUrl()+"login/youxia450/e10adc3949ba59abbe56e057f20f883e";
	request->setUrl(url.c_str());
	//设置网络请求方式
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(this, respond);

	request->setTag("get test1");

	char buff[4096];
	int sz = 0;
	sd.serializer(buff, &sz);
	buff[sz] = '\0';

	char *out = new char[sz+1];
	HttpInfo::getIns()->aes_encrypt(buff, sz, out);
	request->setRequestData(out, sz);
	delete out;
	//提交请求
	HttpClient::getInstance()->send(request);
	//内存释放
	request->release();
}

void XXHttpRequest::getServerDataFromUrl(string url, YMSocketData sd, SEL_HttpResponse respond){
	CCLOG("%s", url.c_str());
	HttpRequest* request = new HttpRequest();
	//设置网络请求地址
	//string url=GameControl::getIns()->getHttpUrl()+"login/youxia450/e10adc3949ba59abbe56e057f20f883e";
	request->setUrl(url.c_str());
	//设置网络请求方式
	request->setRequestType(HttpRequest::Type::GET);

	request->setResponseCallback(this, respond);

	request->setTag("get test1");
	char buff[4096];
	int sz = 0;
	sd.serializer(buff, &sz);
	buff[sz] = '\0';

	char *out = new char[sz + 1];
	HttpInfo::getIns()->aes_encrypt(buff, sz, out);
	request->setRequestData(out, sz);
	delete out;
	//提交请求
	HttpClient::getInstance()->send(request);
	//内存释放
	request->release();
}

void XXHttpRequest::StringReplace(string &strBase, string strSrc, string strDes)
{
	string::size_type pos = 0;
	string::size_type srcLen = strSrc.size();
	string::size_type desLen = strDes.size();
	pos=strBase.find(strSrc, pos); 
	while ((pos != string::npos))
	{
		strBase.replace(pos, srcLen, strDes);
		pos=strBase.find(strSrc, (pos+desLen));
	}
	log("strBase:%s", strBase.c_str());
}

char* XXHttpRequest::getdata(HttpResponse* response, int &psize){
	if (response){
		vector< char> *vc = response->getResponseData();
		psize = vc->size();
		char* temp=new char[psize+1];
		unsigned char cc;
		for (int i = 0; i < psize; i++){
			cc = vc->at(i);
			temp[i]= cc;
		}
		temp[psize] = '\0';
		return temp;
	}
	return "";
}

int XXHttpRequest::getDataSize(HttpResponse* response){
	std::vector<char>* vecs = response->getResponseData();

	return vecs->size();
}

string XXHttpRequest::getRequstData(Dictionary *dict){
	string temp;
	DictElement *elt;
	CCDICT_FOREACH(dict,elt){
		temp += (char *)elt->getObject();
		temp += "/";
		CCLOG("%s",temp.c_str());
	}
	return temp;
}


YMSocketData XXHttpRequest::getSocketDataByStr(char* str, int sz){
	YMSocketData sd;
	if (!str){
		return sd;
	}
	sd.parse(str, sz);
	log("%s",sd.getJsonString().c_str());
	return sd;
}