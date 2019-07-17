/*
	크루스칼 알고리즘은 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘
	>> 다시 말해 최소 비용 신장 트리를 만들기 위한 대표적 알고리즘

	흔히 여러개의 도시가 있을 때, 각 도시를 도로를 이요해 연결하고자 할 때
	비용을 최소한으로 하고자 할 때, 실제로 적용되는 알고리즘


	* 최소비용 신장트리가 되기 위해선
	간선의 수 = 노드의 수 - 1 
	을 만족해야한다.

	크루스칼 알고리즘의 핵심 개념은 
	간선을 거리가 짧은 순서대로 그래프에 포함시키는 것

	일단 모든 노드를 최대한 적은 비용으로 "연결만" 시키면 되기 때문에
	모든 간선 정보를 오름차순으로 정렬한 뒤에
	비용이 적은 간선부터 차근차근 그래프에 포함시키면 됨

	사이클이 발생하면 안됨!
	사이클의 발생 여부는 union find 알고리즘을 적용

	----------------------------------------------------------

	모든 간선들을 거리(비용)을 기준으로 먼저 오름차순 정렬 수행

	1. 정렬된 순서에 맞게 그래프에 포함
	2. 포함시키기 전에 사이클 테이블을 확인
	3. 사이클을 형성하는 경우 간선을 포함하지 않음 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//부모노드를 찾는 함수
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

//두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//같은 부모를 가지는지 확인 (= 같은 그래프에 속해있는지 묻는 것과 같음)
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

//간선 클래스 선언
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator< (Edge &edge) {// 정렬기준 
		return this->distance < edge.distance; //거리가 작은게 먼저
	}

};

int main() {
	const int n = 7; //노드 수
	const int m = 11; //간선의 수

	//벡터에다가 간선의 정보 넣어주는 것
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	//간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	
	//각 정점(노드)이 포함된 그래프가 어디인지 저장
	int parent[n];
	for (int i = 0; i < v.size; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//사이클이 발생하지 않는 경우 그래프에 포함
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1));

	}

}