/*
	지난 시간에는 클래스를 정의하여 묶여있는 데이터를 정렬하는 방식을 알아봤다
	실제 개발에서는 매우 유용한 방식이지만, 실제 코딩 테스트에서는 속도가 중요하므로 적절하지 않음

	클래스를 이용하는 방식은 실무에 적합한 방식
	일반적 프로그래밍 대회와 같이 빠른 개발이 필요할 때는
	페어(pair)라이브러리를 사용하는 것이 효율적이다.
*/

#include <iostream>
#include <vector> // c++프로그래밍 하면 vector라이브러리 굉장히 많이 사용 / 단순 배열 쓸 것인지, 연결리스트 형태로 표현되는 벡터 쓸 것인지는 하다보면 알게됨
//단순 배열과 벡터(연결리스트)는 큰 차이 없다고 일단 생각
#include <algorithm>
#include <string>

using namespace std;

//vector은 원소를 선택적으로 삽입(push) 삭제(pop) 할 수 있는, 배열을 보다 사용하기 쉽게 개편한 자료구조
int main(void) {
	vector <pair<int, string>> v; //여기서 pair는 한 "쌍"의 데이터 다루기 위해 사용하는 라이브러리
	
	//vector로 만든 하나의 리스트
	//push_back :리스트의 마지막 부분에 삽입
	v.push_back(pair<int, string>(90, "박 한 울"));
	v.push_back(pair<int, string>(85, "이 태 일"));
	v.push_back(pair<int, string>(82, "나 동 빈"));
	v.push_back(pair<int, string>(98, "강 종 구"));
	v.push_back(pair<int, string>(79, "이 상 욱"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}

	return 0;
}


