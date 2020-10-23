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
		ANDROID = 0, PC, WEB   //��׿�ˣ����Զˣ���ҳ��
	};

	public:
	//���ӵ�������
	virtual void onConnect() = 0;
	//���Ӵ�����������
	virtual void onConnectError() = 0;
	//��¼�ɹ�
	virtual void onLogin() = 0;    
	//��¼ʧ�ܣ��Ѿ����ӣ����û������������
	virtual void onLoginError()  = 0;
	//����ʧ��
	virtual void onSendError() = 0; 

	//���ӱ��ر�
	virtual void onClosed() = 0;
	//����
	virtual void onBind(wchar_t* strBindto) = 0;   
	//���յ�����Ϣ
	virtual void onMessage(wchar_t* strFromName,wchar_t* strFromID, LinkStatEM link,wchar_t* strMsg)  = 0;
	//���յ�����Ϣ��ֻ�а󶨺���������Ӳ��ܷ����������ݣ����Բ���Ҫ֪���û������û�ID
	virtual void onMessage(BYTE* lpBuffer, int nBufferSize) = 0;

	CLangSocketLibEx* m_pSocketLib;
};

