/*
	병합정렬도 대표적인 분할정복 방법 채틱
	퀵 정렬과 동일하게 O(NlogN)의 시간 복잡도를 가진다

	다만, 퀵 정렬은 피벗 값에 따라서 편향되게 분할할 가능성이 있다는 점에서
	최악의 경우 O(N^2)의 복잡도를 가진다.
	하지만, 병합 정렬은 정확히 반절씩 나눈다는 점에서 
	최악의 경우에도 O(NlogN)의 복잡도를 보장한다.

	병합정렬 : 일단 반으로 쪼개고, 나중에 합치는 알고리즘

	맨 처음에는 모든 배열의 원소가 하나하나 다 쪼개진 상태로 생각
	합칠때는 기본적으로 2의 배수만큼 합친다

	왜 N log N이냐?  너비 N 높이 밑이 2인 logN, 즉 그냥 logN
	높이는 logN인거 알겠다. 너비는 왜 N이냐?
	이미 정렬되어있는 두가지에서 새롭게 정렬하는 것이기 때문에, N밖에 소모안됨

	중요한건, 합치는 순간에! 정렬을 한다
*/

#include <stdio.h>

const int num = 8;
int sorted[8];//정렬된 결과를 담을 배열, 전역으로 선언해줘야함
			  //N개의 데이터 정렬위해서는 크기 N인 배열 추가적으로 필요
			  //매 정렬 시 마다, N크기 배열 할당하는 건 비효율적
//이와 같이 병합정렬은 기존의 데이터를 담을 추가적인 배열공간이 필요하다는 점에서 메모리 활용이 비효율적이라는 문제가 있음


// 두개의 정렬된 부분배열을 이용해서 새롭게 정렬된 배열을 만들어내는 함수
void merge(int a[], int m, int middle, int n) {//m, middle, n은 정렬할 배열에서 시작 중간 끝점 나타냄
	int i = m; // 배열 1의 시작 인덱스
	int j = middle + 1; // 배열 2의 시작 인덱스
	int k = m; // 정렬된 결과를 저장할 배열의 시작 인덱스
	//작은 순서대로 배열에 삽입
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//남은 데이터도 삽입
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열 삽입
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

//일단 나누고 합치기 때문에, 나누는 과정 재귀함수로 구현
void mergeSort(int a[], int m, int n) {
	//크기가 1보다 큰 경우만 분할
	if (m < n) { // 일단 나누고 합침
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main() {
	int array[num] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, num - 1);

	for (int i = 0; i < num; i++) {
		printf("%d ", array[i]);
	}
}