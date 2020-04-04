#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char buf[10000];
	char alpha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int count[26] = { 0, };
	int length = 0;

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�." << endl;

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

	cout << "�� ���ĺ� ��" << length << endl << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " (" << count[i] << ")  : ";
		for (int j = 0; j < count[i]; j++)
			cout << "*";
		cout << endl;
	}
}
