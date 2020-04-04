#include "SmartPhone.h"
using namespace std;

SmartPhone::SmartPhone(bool wifi, bool mobileData) //초기화
{
	this->wifi = false; //와이파이 상태 설정
	this->mobileData = false; //모바일 데이터 상태 설정
	this->type = "Gallaxy S9"; //핸드폰 기종
	this->gallery = 750; //현재 갤러리에 저장되어 있는 사진 갯수
	this->total_message = 37; //현재 확인하지 않은 카카오톡 메시지 갯수
	cout << "스마트폰 객체 생성" << endl;
}

SmartPhone::~SmartPhone()
{
	cout << "스마트폰 객체 소멸" << endl;
}

void SmartPhone::phoneCall(string person)
{
	cout << person << "에게 전화를 겁니다." << endl;
}

void SmartPhone::setAlarm(int hour, int minute, string am_pm)
{
	while (1) {
		cout << "am/pm 00시 00분 : ";
		cin >> am_pm;
		cin >> hour; 
		cin>>minute;

		if (hour <= 0 || hour > 12 || minute < 0 || minute>59) //예외처리
			cout << "숫자를 다시 입력하세요" << endl;
		else if ((am_pm != "am") || (am_pm != "pm")) //예외처리
			cout << "am 혹은 pm만 입력 가능합니다." << endl;
		else {
			cout << am_pm << " " << hour << "시 " << minute << "분으로 알람을 설정했습니다." << endl;
			break;
		}
	}
	
}

void SmartPhone::kakaotalk() 
{	
	if (total_message == 0 || total_message<0) {//예외처리
		cout << "더 이상 확인할 카톡이 없습니다." << endl;
	}
	else {
		int check_message;
		cout << "현재 확인하지 않은 카카오톡 " << this->total_message << "개 입니다." << endl;
		cout << "몇 개를 확인하시겠습니까?";
		cin >> check_message;
		this->total_message -= check_message; //확인한 메시지만틈 개수 감량
	}
	
}

void SmartPhone::wifi(bool on_off)
{	
	if (this->wifi == true && on_off == false) //켜져있는 와이파이를 끌경우
		cout << "와이파이를 껐습니다." << endl;
	if (this->wifi == false && on_off == true) //꺼져있는 와이파이를 킬경우
		cout << "와이파이를 켰습니다." << endl;
}

void SmartPhone::mobileData(bool on_off)
{
	if (this->mobileData == true && on_off == false) //켜져있는 모바일데이터를 끌경우
		cout << "모바일데이터 껐습니다." << endl;
	if (this->mobileData == false && on_off == true) //꺼져있는 모바일데이터를 킬경우
		cout << "모바일데이터를 켰습니다." << endl;
}

void SmartPhone::camera(int gallery) //기능 : 사진을 찍거나 설정된 갤러리에서 사진 삭제 
{
	while (1) {
		char answer;
		cout << "사진을 찍고 싶으면 y를 갤러리에 들어가고 싶으면 g를 누르세요." << endl; 
		cin >> answer;
		if (answer == 'y') {
			char ans;
			cout << "찰칵! 사진을 저장하시겠습니까?(y/n)";
			cin >> ans;
			if (ans == 'y'){
				this->gallery++; //사진 저장 -> 개수 증가
				break;
			}	
			if (ans == 'n')
				break;
		}
		else if (answer == 'g') {
			char an;
			cout << "현재 저장된 사진은 모두 " << gallery << "장 입니다." << endl;
			cout << "사진을 삭제하고 싶으시면 d 누르고 아니면 k누르기" << endl;
			cin >> an;
			if (an == 'd')
				gallery--;
			break;
		}
		else //예외처리
			cout << "y나 g만 입력 가능합니다. 다시 입력!" << endl;
	}

}

void SmartPhone::showInfo()
{
	cout << "스마트폰 기종 : " << this->type << endl;
	if (this->wifi == true)
		cout << "wifi : on" << endl;
	else
		cout << "wifi : off" << endl;
	if (this->mobileData == true)
		cout << "mobileData : on" << endl;
	else
		cout << "mobileData : off" << endl;
	cout << "Gallery : " << this->gallery << "장" << endl;
	cout << "kakaoTalk : " << this->total_message << "개" << endl;

}

