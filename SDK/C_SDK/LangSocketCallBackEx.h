#pragma once

#include <stdlib.h>
#include <iostream>
#include <chrono>

using namespace std;

class CLangSocketLibEx;
class CLangSocketCallBackEx
{
public:
	enum LinkStatEM {
		ANDROID = 0, PC, WEB   //安卓端，电脑端，网页端
	};

	public:
	//连接到服务器
	virtual void onConnect() = 0;
	//连接错误，网络问题
	virtual void onConnectError() = 0;
	//登录成功
	virtual void onLogin() = 0;    
	//登录失败，已经连接，但用户名或密码错误
	virtual void onLoginError()  = 0;
	//发送失败
	virtual void onSendError() = 0; 

	//连接被关闭
	virtual void onClosed() = 0;
	//被绑定
	virtual void onBind(wchar_t* strBindto) = 0;   
	//接收到的消息
	virtual void onMessage(wchar_t* strFromName,wchar_t* strFromID, LinkStatEM link,wchar_t* strMsg)  = 0;
	//接收到的消息，只有绑定后的两个连接才能发二进制数据，所以不需要知道用户名和用户ID
	virtual void onMessage(BYTE* lpBuffer, int nBufferSize) = 0;

	CLangSocketLibEx* m_pSocketLib;
};

