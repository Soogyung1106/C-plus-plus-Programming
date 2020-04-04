#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	map<char, int> alpha;
	//가장 많이 입력된 문자열과 그 횟수를 저장하기 위한 변수
	char c = 'a';
	int maxcount = 0;
	//
	string str;

	cout << "문자열을 입력해주세요:";
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		//맵의 특성을 이용해 키값 참조와 동시에 없으면 삽입(키 : 알파뱃, 값: 횟수)
		alpha[str.at(i)]++;

		if (alpha[str.at(i)] > maxcount) {
			maxcount = alpha[str.at(i)];
			c = str.at(i);
		}
	}

	cout << "가장 많이 사용한 알파벳: " << c << "   횟수: " << maxcount << endl;
	return 0;
}

