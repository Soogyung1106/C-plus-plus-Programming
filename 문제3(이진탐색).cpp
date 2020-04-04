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
		cout << "학번과 점수를 입력해주세요";
		cin >> id >> score;

		if (id == 0 && score == 0)
			break;

		/*studentlist.push_back(Student(id, score));
		studentlist.sort([](Student& s1, Student s2) {
		return s1.score > s2.score;
		});*/

		//이진탐색으로 구현한 중복값 찾기, 정렬된 데이터에선 이진탐색이 성능적으로 빠르다
		//단순히 값의 비교가 아닌, 중간을 기준으로 크기를 비교해가며 찾기 때문에 sort와 마찬가지로 비교함수를 사용한다
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
			cout << "중복된 값입니다" << endl;
		}
	}

	for_each(studentlist.begin(), studentlist.end(), [](Student& s) {
		cout << "학번: " << s.id << endl;
		cout << "점수: " << s.score << endl;
	});

	return 0;
}

