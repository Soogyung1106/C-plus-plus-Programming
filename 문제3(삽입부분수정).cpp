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
		cout << "학번과 점수를 입력해주세요";
		cin >> id >> score;

		if (id == 0 && score == 0)
			break;

		//아무렇게나 삽입하고 정렬하는 방법 
		/*studentlist.push_back(Student(id, score));
		studentlist.sort([](Student& s1, Student s2) {
			return s1.score > s2.score;
		});*/

		//find함수를 사용하여 id값이 존재하는지 확인
		//존재하지 않을 경우 Iterator의 end값을 반환
		//end값은 iterator의 끝을 명시하기 위한 가상의 원소로 실제 값이 존재하지 않음, 수업에서 잘못설명함
		if (find(studentlist.begin(), studentlist.end(), Student(id, 0)) == studentlist.end()) {
			if (studentlist.size() == 0)
				studentlist.push_front(Student(id, score));
			else {
				auto it = studentlist.begin();
				for (; it != studentlist.end(); it++) {
					if ((*it).score < score) {
						//수정사항=> break로 중복삽입 제거
						studentlist.insert(it, Student(id, score));
						break;
					}
				}
				//수정사항=> 조건에 부합하는 삽입장소를 찾지못하면 리스트의 뒷부분에 삽입
				if (it == studentlist.end())
					studentlist.push_back(Student(id, score));
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