/*
	스택을 사용하는 방법
	1. 스택을 구현
	2. 스택 라이브러리 사용
	(일반적 알고리즘 대회에서는 시간이 없기에 스택 라이브러리를 사용한다)

*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;//int 타입 스택 생성
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