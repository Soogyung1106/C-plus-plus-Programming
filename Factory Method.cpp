#include<iostream>
#include<vector>

using namespace std;

class Control
{
public:
	virtual void print() = 0;
	//Factory Method구현
	static Control* CreateInstance(int i);
};

class Window : public Control
{
public:
	void print()
	{
		cout << "This is Window!\n";
	}
};
class Button : public Control
{
public:
	void print()
	{
		cout << "This is Button!\n";
	}
};
class TextEdit : public Control
{
public:
	void print()
	{
		cout << "This is TextEdit!\n";
	}
};

Control* Control::CreateInstance(int i)
{
	if (i == 1)
		return new Window;
	else if (i == 2)
		return new Button;
	else
		return new TextEdit;
}

int main()
{
	vector<Control*> controls;
	int choice;

	while (true)
	{
		cout << "Window(1) Button(2) TextEdit(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;
		else if (choice >= 1 && choice <= 3) {
			//Factory Method를 이용한 객체생성
			controls.push_back(Control::CreateInstance(choice));
		}
		else {
			cout << "잘못선택 하셨습니다.\n";
		}
	}

	for (int i = 0; i < controls.size(); i++)
		controls[i]->print();
	for (int i = 0; i < controls.size(); i++)
		delete controls[i];
}