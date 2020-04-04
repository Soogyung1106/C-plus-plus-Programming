#include <iostream>  
#include <vector>
#include <algorithm>

using namespace std;

struct CPoint
{
	CPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x;
	int y;
};

//x���� �������� ������������ �����ϱ����� �Լ�
//false�̸� ������ �����Ѵ�
bool compare(CPoint& c1, CPoint& c2) {
	return c1.x > c2.x;
}

int main() {
	vector<CPoint> v;

	while (true)
	{
		int x, y;
		cout << "x�� y���� �Է����ּ���";
		cin >> x >> y;

		if (x == 0 && y == 0)
			break;

		v.push_back(CPoint(x, y));
	}

	//Sort�� �����׼����� ������ �������� �����ͱ����� ���İ���(ex.�迭, ���� Ŭ����...)
	sort(v.begin(), v.end(),compare);

	vector<CPoint>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << "x: " << (*it).x << "  y: " << (*it).y << endl;
	}

	return 0;
}
