/*
	실제 알고리즘 대회에서 정렬문제가 나오면 직접 구현하지말고 sort함수 사용

	sort함수의 강력한 점, 우리가 정렬기준을 정해줄 수 있음

	실무에서는 무작위로 나열된 데이터를 정렬하지 않음
	실무에서는 모든 데이터들이 객체로 정리되어 내부적으로 여러개의 변수를 포함하고 있기 때문
	이 경우 가장 중요한 정렬 방식은 '특정한 변수를 기준으로' 정렬하는 것
*/


#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) { // T F값을 기준으로 정렬
	return a > b; // 더 작은 값이 앞으로 가게 됨
}

int main(void) {
	int a[10] = { 3,1,4,1,5,9,2,6,9,7 };
	sort(a, a + 10, compare); //정렬 시작주소와, 마지막 주소 넣어주면, 시작부터 끝까지 정렬하면 되는구나 하고 정렬해줌
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}







/*
const int num = 8;
int sorted[8];

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

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

	if (i <= middle) {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	if (m >= n) return;

	int middle = (m + n) / 2;
	//먼저 반으로 나눈다
	mergeSort(a, m, middle);
	mergeSort(a, middle + 1, n);
	merge(a, m, middle, n); // 합칠때 정렬한다

}

int main() {
	int arr[num] = { 1,3,10,9,8,4,13,16 };
	mergeSort(arr, 0, num-1);

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
}

*/