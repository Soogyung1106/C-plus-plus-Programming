#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Student {
	Student(int id, int score) {
		this->id = id;
		this->score = score;
	}
	int id;
	int score;
};

int main()
{
	list<Student> studentlist;

	while (true)
	{
		int id, score;
		cout << "�й��� ������ �Է����ּ���";
		cin >> id >> score;

		if (id == 0 && score == 0)
			break;

		/*studentlist.push_back(Student(id, score));
		studentlist.sort([](Student& s1, Student s2) {
		return s1.score > s2.score;
		});*/

		//����Ž������ ������ �ߺ��� ã��, ���ĵ� �����Ϳ��� ����Ž���� ���������� ������
		//�ܼ��� ���� �񱳰� �ƴ�, �߰��� �������� ũ�⸦ ���ذ��� ã�� ������ sort�� ���������� ���Լ��� ����Ѵ�
		if (!binary_search(studentlist.begin(), studentlist.end(), Student(id, 0), [](const Student& s1, const Student& s2) {
			return s1.id > s2.id;
		})) 
		{
			if (studentlist.size() == 0)
				studentlist.push_front(Student(id, score));
			else {
				for (auto it = studentlist.begin(); it != studentlist.end(); it++) {
					if ((*it).score < score) {
						studentlist.insert(it, Student(id, score));
					}
				}
			}
		}
		else {
			cout << "�ߺ��� ���Դϴ�" << endl;
		}
	}

	for_each(studentlist.begin(), studentlist.end(), [](Student& s) {
		cout << "�й�: " << s.id << endl;
		cout << "����: " << s.score << endl;
	});

	return 0;
}

