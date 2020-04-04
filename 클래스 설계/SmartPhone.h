#include <iostream>
#include <string>
using std::string;
#pragma once
/*
- ������ ��ü : ����Ʈ��
- ���� ���� ���� : �ϻ��Ȱ���� ���� ���� �� �ִ� ��ǥ�� ��ü�̰�, ����� ����
������ �������� �� ���� ���ٰ� �����ߴ�. 
��� : ��ȭ�ɱ�, �˶�����, īī���� ����, �������� on/off, ����ϵ����� on/off, ī�޶� ���  
*/
class SmartPhone
{	
	bool wifi; //�������� 
	bool mobileData; //������
	int total_message; //���� ī��� �ִ� ����
	int gallery; //���� ����Ǿ� �ִ� ���� ����
	string type; //�ڵ��� ���� 
public:	
	SmartPhone(bool wifi, bool mobileData);  
	~SmartPhone(); 
	/*���*/
	void phoneCall(string person); //��ȭ�ɱ�
	void setAlarm(int hour, int minute, string am_pm); //�˶� ����
	void kakaotalk(); //īī���� Ȯ��
	void wifi(bool on_off); //�������� ����
	void mobileData(bool on_off); //����� ������ ����
	void camera(int gallery); //ī�޶� ���
	void showInfo(); //���� �ڵ����� ���� ���
};

