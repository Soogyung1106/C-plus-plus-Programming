#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	map<char, int> alpha;
	//���� ���� �Էµ� ���ڿ��� �� Ƚ���� �����ϱ� ���� ����
	char c = 'a';
	int maxcount = 0;
	//
	string str;

	cout << "���ڿ��� �Է����ּ���:";
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		//���� Ư���� �̿��� Ű�� ������ ���ÿ� ������ ����(Ű : ���Ĺ�, ��: Ƚ��)
		alpha[str.at(i)]++;

		if (alpha[str.at(i)] > maxcount) {
			maxcount = alpha[str.at(i)];
			c = str.at(i);
		}
	}

	cout << "���� ���� ����� ���ĺ�: " << c << "   Ƚ��: " << maxcount << endl;
	return 0;
}

