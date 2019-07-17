/*
	두 개 이상의 정렬기준을 가지고 정렬 가능
	이때 pair는 이중 pair사용
	pair안에 pair가 들어가는 형식


	정렬할 기준이 3개가 넘어가게 되면, pair를 이용하는게 오히려 더 복잡할 수 있으니
	그때는 그냥 class 구현해서 하는게 더 편할 수도 있다.
	
	정렬기준이 2개 이하인 경우는 pair와 vector을 이용해서 빠르게 프로그래밍 할 수 있다.
*/

#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<string, pair<int, int>> a,
	pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) { //성적이 같다면, 생일이 더 느린사람이 우선순위
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main(void) {
	//pair안에 pair가 또 들어가는 형식
	vector <pair<string, pair<int, int>>> v; // 차례대로 이름 성적 생년월일
	v.push_back(pair<string, pair<int, int>>("나 동 빈", pair<int, int >(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("이 태 일", pair<int, int >(97, 19930518)));
	v.push_back(pair<string, pair<int, int>>("박 한 울", pair<int, int >(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("이 상 욱", pair<int, int >(90, 19921207)));
	v.push_back(pair<string, pair<int, int>>("강 종 구", pair<int, int >(88, 19900302)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}

	return 0;
}