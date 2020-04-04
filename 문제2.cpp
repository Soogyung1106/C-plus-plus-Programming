#include <iostream>
#include <random>

using namespace std;

int main()
{
	vector<int> v;
	//Seed�� ������ ���� ��ü(�ϵ���� ���ҽ��� ���� ����)
	random_device rd;
	//�޸��� Ʈ�����͸� �̿��� ��������
	mt19937_64 rng(rd());
	//���Ժ����� ���� ������ ������ ���� ��ü
	uniform_int_distribution<int> dist(10, 500);

	for (int i = 0; i < 10; i++) {
		v.push_back(dist(rng));
	}

	int a, b;
	cout << "������ index�� ������ �Է����ּ���:";
	cin >> a >> b;

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;

	//Iterator�� ���� ��� ����
	v.erase(v.begin() + a, v.begin() + b + 1);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}
