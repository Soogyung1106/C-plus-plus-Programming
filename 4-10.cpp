#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; };
	~Circle() { }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
};

int main() {
	Circle *circle;
	int count;
	int selected = 0;

	cout << "원의 개수를 입력하시요:";
	cin >> count;

	circle = new Circle[count];

	for (int i = 0; i < count; i++) {
		int r;
		cout << "원" << i + 1<<"의 반지름을 입력하시요:";
		cin >> r;
		circle[i].setRadius(r);
	}

	for (int i = 0; i < count; i++) {
		if (circle[i].getArea() > 100 && circle[i].getArea() < 200)
			selected++;
	}
	cout << "면적이 100과 200사이인 원은 " << selected << "개 입니다" << endl;

	delete[] circle;

	return 0;
}

