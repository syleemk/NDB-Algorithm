/*
	BFS : Breadth First Search
	탐색을 할 때 너비를 우선으로 하여, 탐색을 수행하는 탐색 알고리즘
	특히나, 맹목적인 탐색을 하고자 할 때 사용할 수 있는 탐색 기법
	너비 우선 탐색은 "최단 경로"를 찾아준다는 점에서 최단 길이를 보장해야 할 때 많이 사용

	준비물은 queue (먼저 들어온 것을 먼저 처리해준다는 점에서, 너비우선탐색을 가능하게 해줌)

	BFS는 맨 처음에 시작노드를 큐에 삽입하면서 시작. 또 시작노드를 방문했다고 방문 처리해줌

	이제 BFS는 다음과 같은 간단한 알고리즘에 따라 동작
	1. 큐에서 하나의 노드를 꺼낸다
	2. 해당 노드에 연결된 노드 중 방문하지 않은 노드를 방문하고, 차례대로 큐에 삽입

	위 1, 2 번 계속 반복

	해보면, 1번 노드와 거리가 가까운 것 부터 차례대로 탐색이 이루어짐을 알 수 있다.
	11과의 거리가 1인거 부터 먼저 출력하고 다음으로 거리가 2인것 출력함

	너비우선 탐색은 이 자체로는 큰 의미는 없다
	이를 이용해 다른 알고리즘에 적용한다는 것이 핵심!!!
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int check[7]; // 방문처리위한 배열
vector<int> a[8]; // 7+1개의 벡터가 들어갈 수 있는 배열, 각 노드의 인덱스가 1부터 처리될 수 있도록 하기위해 이렇게 만든 것
//즉, 1부터 7까지 인덱스 사용할 수 있음 (0 사용 안하고)

void bfs(int start) {
	queue <int> q;
	q.push(start);// 큐에 시작점 넣어줌
	check[start] = true;// 큐에 들어간거 방문처리
	while (!q.empty()) { // 반복적으로 알고리즘 수행 (큐가 빌때까지)
		int x = q.front();
		q.pop(); // 큐에서 제일 앞에있는 노드 하나 꺼낸다
		printf("%d ", x);

		for (int i = 0; i < a[x].size(); i++) {//꺼낸 노드에 인접한 노드를 방문
			int y = a[x][i];
			if (!check[y]) {
				q.push(y); //y가 방문했던 적 없다면, queue에 담아주면 됨
				check[y] = true; //방문처리 해준다.
			}
		}
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

	bfs(1);

	return 0;
}

