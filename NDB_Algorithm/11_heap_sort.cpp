/*
	힙 정렬은 병합 정렬과 퀵 정렬 만큼 빠른 정렬 알고리즘

	또한, 고급 프로그래밍 기법으로 갈 수록, 힙(heap)의 개념이 자주 등장하기 때문에 반드시 알고넘어가야할 정렬 알고리즘

	힙 정렬은 "힙 트리 구조"를 이용하는 정렬 방법

	완전 이진트리 : 데이터가 루트 노드부터 시작해서, 자식 노드가 왼쪽에서 오른쪽으로 차례 차례 들어가는 구조의 이진트리
					이진 트리의 노드가 중간에 비어있지 않고, 빽빽히 가득 찬 구조
	힙 : 최솟값이나 최댓값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 하는 트리
		 힙에는 최대 힙과 최소 힙이 존재하는데, 최대 힙은 부모노드가 자식노드보다 큰 힙
		 즉, 더 큰 값이 위로가는 것, 더 큰 값이 부모가 됨

	힙 정렬 하기 위해선, 정해진 데이터를 힙 구조를 가지도록 만들어야 함

	힙 정렬을 수행하기 위해선, 힙 생성 알고리즘을 사용
	힙 생성 알고리즘은  "하나의 노드"에 대해서 수행
	또한, 해당 "하나의 노드"를 제외하고는, 최대 힙이 구성되어있는 상태라고 가정
	특정한 노드의 두 자식 중에 더 큰 자식과 자신을 바꾸는 알고리즘

	힙 생성 알고리즘 시간 복잡도
	힙의 높이 밑이 2인 log N * 모든 노드 N개 * 1/2
	즉 O(NlogN)

	완전 이진트리 같은 경우, 그냥 배열에 담아도 아무 상관 없음

	힙 정렬은 추가적인 배열이 필요하지 않다는 점에서
	병합정렬보다 메모리 측면에서 효율적
	또 항상 NlogN의 시간복잡도를 보장한다는 점에서 매우 강력

	하지만, 단순히 속도만 가지고 비교하면, 퀵정렬이 평균적으로 더 빠르기에 힙정렬이 일반적으로 많이 사용되지는 않음

*/

#include <stdio.h>

int number = 9;
int heap[9] = { 3,1,4,1,5,9,2,6,9 };

int main() {
	// 먼저 전체 트리 구조를 최대 힙 구조로 바꾼다.
	for (int i = 1; i < number; i++) {// 힙 생성
		int c = i; // child 노드
		do {
			int root = (c - 1) / 2; // root는 부모노드
			if (heap[root] < heap[c]) {// 부모보다 자식노드가 큰 경우 위치 바꿈
				int temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp;
			}
			c = root; // 부모노드로 이동
		} while (c != 0);
	}

	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) {
	// 먼저 루트노드와 제일 마지막 노드를 바꿔준다
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int root = 0;
		int c = 1; //c는 child노드
		do {
			c = 2 * root + 1;
			//자식 중에 더 큰 값을 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {//c가 범위를 벗어나지 않도록 제한
				c++; // 오른쪽이 더 크면, c를 1 더해줘서 오른쪽으로 이동시켜주는 것
			}
			//루트보다 자식이 더 크다면 교환
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c; // 루트를 c로 이동하여 검사
		} while (c < i);

	}

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}

	return 0;
}

int main() {
	//힙 생성
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c > 0);
	}

	for (int i = number - 1; i > 0; i--) {
		int root = 0;
		int c = 1;

		int temp = heap[i];
		heap[i] = heap[root];
		heap[root] = temp;

		do {
			c = 2 * root + 1;
			if (heap[c] < heap[c + 1] && c < i-1) c++; //c+1이 범위를 범위를 넘지 않도록 c+1 < i => c < i-1
			if (heap[root] < heap[c] && c <i) { // c<i
				temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp;
			}
			root = c;
		} while (c < i);
	}
	

}
