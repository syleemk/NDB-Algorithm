#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 학생을 점수별로 정렬하는 시스템 구현
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// 정렬기준은 점수가 작은 순서
	// 특정한 변수를 기준으로 해서 정렬 (여기서는 score기준)
	bool operator< (Student &student) {//연산자 오버로딩 ? 이라네 나중에 알아보기
		return this->score < student.score;
	}
};

int main() {
	Student students[] = {
		Student("이 수 영", 90),
		Student("이 상 욱", 93),
		Student("하 현 준", 78),
		Student("박 부 용", 99),
		Student("임 유 진", 63),
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}