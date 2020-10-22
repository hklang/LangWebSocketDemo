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
	enum SOCKETSTACT {         //��ʶ�Ƿ�Ϊ������
		MAIN = 0,
		SERVER,
		TEMP
	};
	//��ʼ��
	virtual void Init(CLangSocketCallBackEx* pCallBackObj, SOCKETSTACT emStact) = 0;
	//�ͷ�
	virtual void Release() = 0;
	//�õ���¼���û���
	virtual wchar_t* GetUserName(wchar_t* strUserName, int nSize) = 0;
	//�õ���¼���û���
	virtual wchar_t* GetUserId(wchar_t* strUserId, int nSize) = 0;
	//��ȡ��¼������
	virtual wchar_t* GetPassWord(wchar_t* strPassWord, int nSize) = 0;
	//��ȡ�󶨵��û���
	virtual wchar_t* GetBindTo(wchar_t* strBindTo, int nSize) = 0;
	//��ȡ��ǰ�Ƿ�Ϊ������
	virtual SOCKETSTACT GetSocketStact() = 0;
	//��ʼ��¼
	virtual void StartLogin(wchar_t* strUserName, wchar_t* strPassWord) = 0;
	
	//ƴ����¼����������Ѿ���һ���û�����¼�ˣ�������û�����Ϊ��ʶ���Լ��Ϳ��Ե�¼�������������һ���û���
	virtual void StartLoginAsFather(wchar_t* strFatherName) = 0;
	//ƴ����¼�����Ұ�һ�����͵��û�
	virtual void StartLoginAsFather(wchar_t* strFatherName, wchar_t* strBindTo) = 0;

	//������������
	virtual void SendToUserId(wchar_t* strToUserID, wchar_t* strMsg) = 0;
	//������������
	virtual void SendToUserName(wchar_t* strToUserName, wchar_t* strMsg) = 0;
	//�����������ӷ�����������
	virtual void SendToAllFather(wchar_t* strMsg) = 0;
	//�����б��ض˷�����������
	virtual void SendToAllServer(wchar_t* strMsg) = 0;
	virtual void SendToBind(wchar_t* strMsg) = 0;

	//���ͻ�������
	virtual void SendToUserId(wchar_t* strToUserID, BYTE* lpSendBuffer, int nSendBufferSize) = 0;
	virtual void SendToBind(BYTE* lpSendBuffer, int nSendBufferSize) = 0;
	
	//�ر�����
	virtual void Close() = 0;

};
