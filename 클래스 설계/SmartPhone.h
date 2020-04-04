#include <iostream>
#include <string>
using std::string;
#pragma once
/*
- 선택한 객체 : 스마트폰
- 주제 설정 이유 : 일상생활에서 쉽게 접할 수 있는 대표적 객체이고, 기능이 많기
때문에 생각봐야 할 것이 많다고 생각했다. 
기능 : 전화걸기, 알람설정, 카카오톡 답장, 와이파이 on/off, 모바일데이터 on/off, 카메라 기능  
*/
class SmartPhone
{	
	bool wifi; //와이파이 
	bool mobileData; //데이터
	int total_message; //현재 카톡와 있는 개수
	int gallery; //현재 저장되어 있는 사진 갯수
	string type; //핸드폰 기종 
public:	
	SmartPhone(bool wifi, bool mobileData);  
	~SmartPhone(); 
	/*기능*/
	void phoneCall(string person); //전화걸기
	void setAlarm(int hour, int minute, string am_pm); //알람 설정
	void kakaotalk(); //카카오톡 확인
	void wifi(bool on_off); //와이파이 설정
	void mobileData(bool on_off); //모바일 데이터 설정
	void camera(int gallery); //카메라 기능
	void showInfo(); //현재 핸드폰의 상태 출력
};

