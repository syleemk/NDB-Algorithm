#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// �л��� �������� �����ϴ� �ý��� ����
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// ���ı����� ������ ���� ����
	// Ư���� ������ �������� �ؼ� ���� (���⼭�� score����)
	bool operator< (Student &student) {//������ �����ε� ? �̶�� ���߿� �˾ƺ���
		return this->score < student.score;
	}
};

int main() {
	Student students[] = {
		Student("�� �� ��", 90),
		Student("�� �� ��", 93),
		Student("�� �� ��", 78),
		Student("�� �� ��", 99),
		Student("�� �� ��", 63),
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}