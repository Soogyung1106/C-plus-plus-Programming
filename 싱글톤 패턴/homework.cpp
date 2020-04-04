#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Shape
{
public:
	virtual void print() = 0;//���� �����Լ��� ��ü ���� �Ұ�
	//Factory �Լ� 
	static Shape* CreateInstance(int i);
};

class Line :public Shape
{
public:
	virtual void print()
	{
		cout << "Line ";
	}
};

class Circle :public Shape
{
public:
	virtual void print()
	{
		cout << "Circle ";
	}
};

class Rect :public Shape
{
public:
	virtual void print()
	{
		cout << "Rect ";
	}
};

Shape* Shape::CreateInstance(int i)
{
	if (i == 1)
		return new Line;
	else if (i == 2)
		return new Circle;
	else
		return new Rect;
}

class GraphicEditor //�̱������� �ۼ��ϰ� Vector�� Shape���� �����ض�
{
private:
	static GraphicEditor* instance;
	GraphicEditor() {}; //�����ڸ� private���� ó��
	//getInstance()�Լ����� public���� ��ü�� ���� -> ������� instance���� ����Ͽ� ����
public:
	static GraphicEditor& getInstance() {
		if (!instance) {
			instance = new GraphicEditor;
		}
		return *instance;
	}

	void func1() {
		vector<Shape*> shapes;
		int choice;

		while (true)
		{
			cout << "Line(1) Circle(2) Rect(3) Go(0): ";
			cin >> choice;
			if (choice == 0)
				break;
			else if (choice >= 1 && choice <= 3) {
				//Factory Method�� �̿��� ��ü����
				shapes.push_back(Shape::CreateInstance(choice));
			}
			else {
				cout << "�߸����� �ϼ̽��ϴ�.\n";
			}
		}

		for (int i = 0; i < shapes.size(); i++)
			shapes[i]->print();
		for (int i = 0; i < shapes.size(); i++)
			delete shapes[i];
	}
};



GraphicEditor* GraphicEditor::instance = NULL;

int main(){
	
	GraphicEditor::getInstance().func1();

	
}


