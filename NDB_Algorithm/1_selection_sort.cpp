/*
	선택정렬은 말그대로 선택해서 정렬하는 것

	오름차순으로 정렬하는 경우, 가장 작은 값을 "선택"해서 제일 앞으로 보내는 방식


	10개의 원소 정렬하는 경우

	10 + 9 + 8 + ... + 1 
	=> N * (N+1) /2
	=> 컴퓨터에서 상수를 더하거나 상수로 나누는 것은 N에 비해 그 영향이 미미하므로 무시한다.
	=> N * N
	=> O(N * N) : 특정 알고리즘의 수행시간 간략하게 표현하는 것을 '빅 오 표기법이라 함'
	특정알고리즘 총 연산회수 간략하게 표현

	즉, 선택정렬의 시간복잡도 O(N^2)
	10000개의 데이터 연산하려면 일억번정도 연산해야함
	N^2은 굉장히 느린 비효율적인 알고리즘

*/

#include <stdio.h>

/*
int main(void) {
	int min, index, temp;
	int arr[10] = { 3,1,4,1,5,9,2,6,8,7 };

	for (int i = 0; i < 9; i++) {
		min = arr[i];
		index = i;
		for (int j = i+1; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	puts("");
}
*/

int main() {
	int i, j, min, index, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	puts("");
	return 0;
}