/*
	������ ����ϴ� ���
	1. ������ ����
	2. ���� ���̺귯�� ���
	(�Ϲ��� �˰��� ��ȸ������ �ð��� ���⿡ ���� ���̺귯���� ����Ѵ�)

*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;//int Ÿ�� ���� ����
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}