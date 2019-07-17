/*
	일반적으로 온라인 시스템같은 경우 1초에 1억번정도 연산이 가능하다고 생각하면됨
	입력의 개수가 1000개면 N^2인경우 100만 정도밖에 안되니까 O(N^2)써도 됨
	즉 , 선택 버블 삽입 정렬 중 사용가능

	c++의 algorithm라이브러리를 사용해서
	sort함수를 사용하여 빠르고 쉽게 정렬할 수 있음 (추후에 나옴)
	sort함수의 내부적 구현 원리는 퀵정렬
	하지만, 퀵정렬을 기본으로하되 최악의 경우에도 NlogN이 나오게 구현되어있음

*/

#include <iostream>

using namespace std;
/*
//2750
int main() {
	int num, temp;
	int arr[1001];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", arr + i);
	}

	//삽입 정렬
	for (int i = 0; i < num-1; i++) {
		int j = i;
		while (arr[j + 1] <= arr[j] && j>=0) {//while문에서는 등호 포함 여부 중요(while문 지속을 결정하니까)
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}
}
*/

/*
//2752

int main() {
	int arr[3];
	int temp;

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	//버블정렬
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
}
*/

//2751
//시간복잡도 O(NlogN)요구 (1초당 1억번연산한다고 생각해라)



void quickSort(int * arr, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int temp;
	int i = start + 1;
	int j = end;

	while (i <= j) {
		while (arr[i] <= arr[pivot] && i <=end) {
			//printf("%d %d\n", arr[i], arr[pivot]);
			//printf("%d", arr[i] <= arr[pivot]);
			i++;
		}
		while (arr[j] >= arr[pivot] && j > start) {
			j--;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}

int arr[1000001];

int main() {
	
	int num;

	
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	quickSort(arr, 0, num - 1);

	for (int i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}
}