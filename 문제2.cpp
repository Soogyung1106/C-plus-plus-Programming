#include <iostream>
#include <random>

using namespace std;

int main()
{
	vector<int> v;
	//Seed값 생성을 위한 객체(하드웨어 리소스로 부터 생성)
	random_device rd;
	//메르센 트위스터를 이용한 난수생성
	mt19937_64 rng(rd());
	//정규분포를 갖는 정수값 생성을 위한 객체
	uniform_int_distribution<int> dist(10, 500);

	for (int i = 0; i < 10; i++) {
		v.push_back(dist(rng));
	}

	int a, b;
	cout << "제거할 index의 범위를 입력해주세요:";
	cin >> a >> b;

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;

	//Iterator를 통해 요소 제거
	v.erase(v.begin() + a, v.begin() + b + 1);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}
