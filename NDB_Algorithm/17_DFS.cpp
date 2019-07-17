/*
	DFS : Depth First Search 깊이 우선 

	깊이우선탐색은 너비우선탐색과 마찬가지로 맹목적으로 각 노드를 탐색할 때 주로 사용

	너비우선탐색의 경우 큐를 사용했지만,
	깊이우선탐색의 경우 스택을 사용한다.
	더불어 스택을 사용하지 않아도 구현이 가능하다는 특징이 있음
	(왜냐하면, 컴퓨터는 구조적으로 항상 스택의 원리를 사용하기 때문)    
	(그래서 스택을 사용하지 않고, 단순히 재귀함수만 써도 구현이 가능)
	

	BFS와 마찬가지로 한개의 스택과 한개의 그래프가 준비되어있다

	BFS와 마찬가지로
	시작노드를 스택에 넣어주고 방문처리하는게 먼저

	1. 스택의 최상단 노드를 확인
	2. 최상단 노드에게 방문하지 않은 인접 노드가 있으면, 그 노드를 스택에 넣고 방문처리
	   방문하지 않은 인접노드가 없으면 스택에서 최상단 노드를 뺀다.

	위 알고리즘을 계속 반복해서 수행

	BFS와 마찬가지로 이 자체로는 큰 의미가 없고
	DFS를 활용해서 다양한 그래프 알고리즘들을 구현할 수 있음

*/

#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int check[7];
vector<int> a[8]; //총 7개의 노드가 각각 인접한 노드를 가질 수 있도록 배열 만들어줌

void dfs(int x) {
	if (check[x]) return; // 방문한 노드면 리턴
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {// 인접 노드 차례로 방문
		int y = a[x][i];
		dfs(y); //인접한 노드를 대상으로 dfs수행
	}
}

int main() {
	//한개의 그래프 연결된 상태 표시

	//하나의 간선마다 이런 작업해줌
	//1과 2를 연결
	a[1].push_back(2);
	a[2].push_back(1);

	//1과 3을 연결
	a[1].push_back(3);
	a[3].push_back(1);

	//2와 3을 연결
	a[2].push_back(3);
	a[3].push_back(2);

	//2와 4를 연결
	a[2].push_back(4);
	a[4].push_back(2);

	//2와 5를 연결
	a[2].push_back(5);
	a[5].push_back(2);

	//3과 6을 연결
	a[3].push_back(6);
	a[6].push_back(3);

	//3과 7을 연결
	a[3].push_back(7);  
	a[7].push_back(3);

	//4와 5를 연결
	a[4].push_back(5);
	a[5].push_back(4);

	//6과 7을 연결
	a[6].push_back(7);
	a[7].push_back(6);

	dfs(1);

	return 0;
}