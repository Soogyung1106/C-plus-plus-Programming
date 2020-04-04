#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char buf[10000];
	char alpha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int count[26] = { 0, };
	int length = 0;

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;

	cin.getline(buf, 10000, ';');

	for (int i = 0; i < 10000; i++) {
		if (buf[i] == '\0')
			break;

		for (int j = 0; j < 26; j++) {
			if (isalpha(buf[i]) && alpha[j] == tolower(buf[i])) {
				count[j]++;
				length++;
				break;
			}
		}
	}

	cout << "총 알파벳 수" << length << endl << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " (" << count[i] << ")  : ";
		for (int j = 0; j < count[i]; j++)
			cout << "*";
		cout << endl;
	}
}
