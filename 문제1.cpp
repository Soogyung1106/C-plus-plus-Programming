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

//x값을 기준으로 내림차순으로 정렬하기위한 함수
//false이면 순서를 변경한다
bool compare(CPoint& c1, CPoint& c2) {
	return c1.x > c2.x;
}

int main() {
	vector<CPoint> v;

	while (true)
	{
		int x, y;
		cout << "x와 y값을 입력해주세요";
		cin >> x >> y;

		if (x == 0 && y == 0)
			break;

		v.push_back(CPoint(x, y));
	}

	//Sort는 랜덤액세스가 가능한 순차적인 데이터구조만 정렬가능(ex.배열, 벡터 클래스...)
	sort(v.begin(), v.end(),compare);

	vector<CPoint>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << "x: " << (*it).x << "  y: " << (*it).y << endl;
	}

	return 0;
}
