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

bool operator==(const Student& s1, const Student& s2) {
	return s1.id == s2.id;
}


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

		//�ƹ����Գ� �����ϰ� �����ϴ� ��� 
		/*studentlist.push_back(Student(id, score));
		studentlist.sort([](Student& s1, Student s2) {
			return s1.score > s2.score;
		});*/

		//find�Լ��� ����Ͽ� id���� �����ϴ��� Ȯ��
		//�������� ���� ��� Iterator�� end���� ��ȯ
		//end���� iterator�� ���� ����ϱ� ���� ������ ���ҷ� ���� ���� �������� ����, �������� �߸�������
		if (find(studentlist.begin(), studentlist.end(), Student(id, 0)) == studentlist.end()) {
			if (studentlist.size() == 0)
				studentlist.push_front(Student(id, score));
			else {
				auto it = studentlist.begin();
				for (; it != studentlist.end(); it++) {
					if ((*it).score < score) {
						//��������=> break�� �ߺ����� ����
						studentlist.insert(it, Student(id, score));
						break;
					}
				}
				//��������=> ���ǿ� �����ϴ� ������Ҹ� ã�����ϸ� ����Ʈ�� �޺κп� ����
				if (it == studentlist.end())
					studentlist.push_back(Student(id, score));
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