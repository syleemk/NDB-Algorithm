/*
	지난시간까지 다뤘떤, 선택 버블 삽입정렬의 시간복잡도 모두 O(N^2)

	데이터가 10만개만 넘어가도, 일반적인 상황에서 사용하기 어려워짐
	따라서 더욱 빠른 정렬 알고리즘 사용될 필요

	그 대표적인 예가 퀵정렬

	퀵정렬은 대표적인 "분할정복" 알고리즘으로, <평균> 속도가 O(N*logN)
	logN같은 경우 굉장히 작은 숫자! > 사실상 거의 상수라고 봐도 무관

	N * 밑이 2인 log N(배열을 반씩 쪼개는 과정)

	퀵 정렬은, 하나의 큰 문제를 두 개의 작은 문제로 분할하는 식으로 빠르게 정렬
	쉽게 말하면, 특정한 값을 기준으로 큰 숫자와 작은 숫자를 서로 교환한 뒤에 배열을 반으로 나눔

	" 특정한 값을 기준으로 큰 숫자와 작은 숫자를 나누는게 어떨까?"

	이 특정한 기준 값을 "피벗"이라고 한다. 보통 첫 번째 원소를 피벗 값으로 설정하고 사용


	피벗값을 설정하는 것에 따라서 
	최악의 경우 O(N^2)까지 복잡도가 나올 수 있다

	하지만, 대부분의 경우에 가장 빠르게 작동하기에 가장 사랑받는 방식
	일반적으로 가장 빠른 정렬방식

	알고리즘 대회에서 O(N)의 복잡도를 요구하는 경우 퀵정렬을 사용하면 틀리는 경우도 있음

	어느경우가 최악의 경우?
	>>이미 정렬이 되어있는 경우 or 거의 정렬이 되어있는 경우

*/

#include <stdio.h>
//퀵정렬은 깔끔한 구현을 위해 재귀함수를 사용하는 경우가 많음

int number = 11;
int data[11] = { 24,32,11,15,62,3,9,13,22,5,10};

void quickSort(int * data, int start, int end) {
	if (start >= end) {// 원소가 1개인 경우 
		return;
	}

	int key = start; // 키는 첫번째 원소
	int i = start + 1; // 키 값보다 큰 값 찾는 인덱스
	int j = end; // 키 값보다 작은 값 찾는 인덱스
	int temp;

	while (i <= j) {// 엇갈릴 때까지 반복
		while (data[i] <= data[key]) {// 키 값보다 큰 값을 만날 때까지 오른쪽으로 이동
			i++;
		 }
		while (data[j] >= data[key] && j > start) {// 키 값보다 작은 값을 만날 때까지 왼쪽으로 이동
			j--;
		}

		//오른쪽 가는 거에는 왜 제한 안검? 
		//엇갈려서 키 값 교체할때, 작은값(왼쪽으로 가는값)하고 키값을 교체하기 때문
		if (i > j) {// 현재 엇갈린 상태면 키 값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {// 엇갈리지 않은 경우 두 개의 값을 서로 교환
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	//결과적으로 데이터 엇갈려서 바깥으로 빠져나오는 경우
	quickSort(data, start, j - 1);// 키 값을 기준으로 왼쪽과
	quickSort(data, j + 1, end); // 오른쪽에서 각각 정렬을 다시 수행


}


int main() {
	quickSort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}

}

/*
int num = 10;
int data[10] = { 3,4,10,9,7,29,3,0,6,14 };

void quickSort(int * data, int start, int end) {
if (start >= end) return;

int i = start + 1;
int j = end;
int temp;
int key = start;

while (i <= j) {// 엇갈리는 경우
while (data[i] <= data[key]) {
i++;
}
while (data[j] >= data[key]&& j>=start) {
j--;
}
if (i<j) {
temp = data[i];
data[i] = data[j];
data[j] = temp;
}
else {
temp = data[key];
data[key] = data[j];
data[j] = temp;
}
}
quickSort(data, start, j - 1);
quickSort(data, j + 1, end);
}


int main() {
quickSort(data, 0, num - 1);
for (int i = 0; i < num; i++) {
printf("%d ", data[i]);
}
}
*/