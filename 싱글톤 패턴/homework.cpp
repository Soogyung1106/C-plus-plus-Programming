#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Shape
{
public:
	virtual void print() = 0;//순수 가상함수는 객체 생성 불가
	//Factory 함수 
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

class GraphicEditor //싱글톤으로 작성하고 Vector로 Shape들을 관리해라
{
private:
	static GraphicEditor* instance;
	GraphicEditor() {}; //생성자를 private으로 처리
	//getInstance()함수만을 public으로 객체를 생성 -> 멤버변수 instance만을 사용하여 설계
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
				//Factory Method를 이용한 객체생성
				shapes.push_back(Shape::CreateInstance(choice));
			}
			else {
				cout << "잘못선택 하셨습니다.\n";
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


