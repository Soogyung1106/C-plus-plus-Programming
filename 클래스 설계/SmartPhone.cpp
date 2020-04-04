#include "SmartPhone.h"
using namespace std;

SmartPhone::SmartPhone(bool wifi, bool mobileData) //�ʱ�ȭ
{
	this->wifi = false; //�������� ���� ����
	this->mobileData = false; //����� ������ ���� ����
	this->type = "Gallaxy S9"; //�ڵ��� ����
	this->gallery = 750; //���� �������� ����Ǿ� �ִ� ���� ����
	this->total_message = 37; //���� Ȯ������ ���� īī���� �޽��� ����
	cout << "����Ʈ�� ��ü ����" << endl;
}

SmartPhone::~SmartPhone()
{
	cout << "����Ʈ�� ��ü �Ҹ�" << endl;
}

void SmartPhone::phoneCall(string person)
{
	cout << person << "���� ��ȭ�� �̴ϴ�." << endl;
}

void SmartPhone::setAlarm(int hour, int minute, string am_pm)
{
	while (1) {
		cout << "am/pm 00�� 00�� : ";
		cin >> am_pm;
		cin >> hour; 
		cin>>minute;

		if (hour <= 0 || hour > 12 || minute < 0 || minute>59) //����ó��
			cout << "���ڸ� �ٽ� �Է��ϼ���" << endl;
		else if ((am_pm != "am") || (am_pm != "pm")) //����ó��
			cout << "am Ȥ�� pm�� �Է� �����մϴ�." << endl;
		else {
			cout << am_pm << " " << hour << "�� " << minute << "������ �˶��� �����߽��ϴ�." << endl;
			break;
		}
	}
	
}

void SmartPhone::kakaotalk() 
{	
	if (total_message == 0 || total_message<0) {//����ó��
		cout << "�� �̻� Ȯ���� ī���� �����ϴ�." << endl;
	}
	else {
		int check_message;
		cout << "���� Ȯ������ ���� īī���� " << this->total_message << "�� �Դϴ�." << endl;
		cout << "�� ���� Ȯ���Ͻðڽ��ϱ�?";
		cin >> check_message;
		this->total_message -= check_message; //Ȯ���� �޽�����ƴ ���� ����
	}
	
}

void SmartPhone::wifi(bool on_off)
{	
	if (this->wifi == true && on_off == false) //�����ִ� �������̸� �����
		cout << "�������̸� �����ϴ�." << endl;
	if (this->wifi == false && on_off == true) //�����ִ� �������̸� ų���
		cout << "�������̸� �׽��ϴ�." << endl;
}

void SmartPhone::mobileData(bool on_off)
{
	if (this->mobileData == true && on_off == false) //�����ִ� ����ϵ����͸� �����
		cout << "����ϵ����� �����ϴ�." << endl;
	if (this->mobileData == false && on_off == true) //�����ִ� ����ϵ����͸� ų���
		cout << "����ϵ����͸� �׽��ϴ�." << endl;
}

void SmartPhone::camera(int gallery) //��� : ������ ��ų� ������ ���������� ���� ���� 
{
	while (1) {
		char answer;
		cout << "������ ��� ������ y�� �������� ���� ������ g�� ��������." << endl; 
		cin >> answer;
		if (answer == 'y') {
			char ans;
			cout << "��Ĭ! ������ �����Ͻðڽ��ϱ�?(y/n)";
			cin >> ans;
			if (ans == 'y'){
				this->gallery++; //���� ���� -> ���� ����
				break;
			}	
			if (ans == 'n')
				break;
		}
		else if (answer == 'g') {
			char an;
			cout << "���� ����� ������ ��� " << gallery << "�� �Դϴ�." << endl;
			cout << "������ �����ϰ� �����ø� d ������ �ƴϸ� k������" << endl;
			cin >> an;
			if (an == 'd')
				gallery--;
			break;
		}
		else //����ó��
			cout << "y�� g�� �Է� �����մϴ�. �ٽ� �Է�!" << endl;
	}

}

void SmartPhone::showInfo()
{
	cout << "����Ʈ�� ���� : " << this->type << endl;
	if (this->wifi == true)
		cout << "wifi : on" << endl;
	else
		cout << "wifi : off" << endl;
	if (this->mobileData == true)
		cout << "mobileData : on" << endl;
	else
		cout << "mobileData : off" << endl;
	cout << "Gallery : " << this->gallery << "��" << endl;
	cout << "kakaoTalk : " << this->total_message << "��" << endl;

}

