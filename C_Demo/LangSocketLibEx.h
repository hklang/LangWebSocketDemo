#pragma once

#define DLLEXPORT_API __declspec(dllexport)

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include "LangSocketCallBackEx.h"

using namespace std;
#define LANGSOCKET_MAX_LEN  (5 * 1024)

class CLangSocketLibEx
{
	
public:
	enum SOCKETSTACT {         //标识是否为主链接
		MAIN = 0,
		SERVER,
		TEMP
	};
	//初始化
	virtual void Init(CLangSocketCallBackEx* pCallBackObj, SOCKETSTACT emStact) = 0;
	//释放
	virtual void Release() = 0;
	//得到登录的用户名
	virtual wchar_t* GetUserName(wchar_t* strUserName, int nSize) = 0;
	//得到登录的用户名
	virtual wchar_t* GetUserId(wchar_t* strUserId, int nSize) = 0;
	//获取登录的密码
	virtual wchar_t* GetPassWord(wchar_t* strPassWord, int nSize) = 0;
	//获取绑定的用户名
	virtual wchar_t* GetBindTo(wchar_t* strBindTo, int nSize) = 0;
	//获取当前是否为主链接
	virtual SOCKETSTACT GetSocketStact() = 0;
	//开始登录
	virtual void StartLogin(wchar_t* strUserName, wchar_t* strPassWord) = 0;
	
	//拼爹登录，就是如果已经有一个用户名登录了，用这个用户名作为标识，自己就可以登录，并且随机分配一个用户名
	virtual void StartLoginAsFather(wchar_t* strFatherName) = 0;
	//拼爹登录，并且绑定一个发送的用户
	virtual void StartLoginAsFather(wchar_t* strFatherName, wchar_t* strBindTo) = 0;

	//发送文字数据
	virtual void SendToUserId(wchar_t* strToUserID, wchar_t* strMsg) = 0;
	//发送文字数据
	virtual void SendToUserName(wchar_t* strToUserName, wchar_t* strMsg) = 0;
	//向所有主链接发送文字数据
	virtual void SendToAllFather(wchar_t* strMsg) = 0;
	//向所有被控端发送文字数据
	virtual void SendToAllServer(wchar_t* strMsg) = 0;
	virtual void SendToBind(wchar_t* strMsg) = 0;

	//发送缓冲数据
	virtual void SendToUserId(wchar_t* strToUserID, BYTE* lpSendBuffer, int nSendBufferSize) = 0;
	virtual void SendToBind(BYTE* lpSendBuffer, int nSendBufferSize) = 0;
	
	//关闭连接
	virtual void Close() = 0;

};
