/*
	union find(합집합 찾기) 알고리즘은 대표적인 그래프 알고리즘
	서로소 집합(Disjoint Set) 알고리즘이라고도 부른다.
	합집합을 찾는 것은 서로소를 찾는 것, 다시말해서 서로 같은 집합이 아닌 것을 찾는 것과 같아서
	이렇게도 부르는 것.

	여러개의 노드가 존재할 때, 두개의 노드를 선택해서 
	현재 이 두 노드가 서로 같은 그래프에 속하는지 판별하는 그래프 알고리즘

	나중에 고급 알고리즘 기법에도 쓰이는 원리므로 확실히 이해!
	>> 크루스칼 알고리즘 등..

	각각을 하나의 집합으로 가지는 여러개의 노드가 있다

	서로다른 노드를 합칠때(union) 일반적으로 더 작은 값을 부모노드가 되도록 합친다.

	1-2-3 차례로 연결된 노드가 있을 때, 1과 2가 연결되고 2-3이 연결되어있음을
	표만 보고 알 수 있으나, 1과 3이 연결되었다는 사실은 바로 알 수 없음

	노드 1,2,3의 부모가 모두 1이기 때문에 이 세가지 노드는 모두 같은 그래프에 속한다 할 수 있음

	find 알고리즘은 두 개의 노드의 부모노드를 확인하여, 현재 같은 집합에 속하는지 확인하는 알고리즘이다.

*/

#include <stdio.h>

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

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i; //기본적으로 자기자신을 부모로 가리키도록 만들어줌
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
}
