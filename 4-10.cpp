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

	cout << "���� ������ �Է��Ͻÿ�:";
	cin >> count;

	circle = new Circle[count];

	for (int i = 0; i < count; i++) {
		int r;
		cout << "��" << i + 1<<"�� �������� �Է��Ͻÿ�:";
		cin >> r;
		circle[i].setRadius(r);
	}

	for (int i = 0; i < count; i++) {
		if (circle[i].getArea() > 100 && circle[i].getArea() < 200)
			selected++;
	}
	cout << "������ 100�� 200������ ���� " << selected << "�� �Դϴ�" << endl;

	delete[] circle;

	return 0;
}

