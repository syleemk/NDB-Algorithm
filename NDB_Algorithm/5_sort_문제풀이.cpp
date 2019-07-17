/*
	�Ϲ������� �¶��� �ý��۰��� ��� 1�ʿ� 1������� ������ �����ϴٰ� �����ϸ��
	�Է��� ������ 1000���� N^2�ΰ�� 100�� �����ۿ� �ȵǴϱ� O(N^2)�ᵵ ��
	�� , ���� ���� ���� ���� �� ��밡��

	c++�� algorithm���̺귯���� ����ؼ�
	sort�Լ��� ����Ͽ� ������ ���� ������ �� ���� (���Ŀ� ����)
	sort�Լ��� ������ ���� ������ ������
	������, �������� �⺻�����ϵ� �־��� ��쿡�� NlogN�� ������ �����Ǿ�����

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

	//���� ����
	for (int i = 0; i < num-1; i++) {
		int j = i;
		while (arr[j + 1] <= arr[j] && j>=0) {//while�������� ��ȣ ���� ���� �߿�(while�� ������ �����ϴϱ�)
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

	//��������
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
//�ð����⵵ O(NlogN)�䱸 (1�ʴ� 1��������Ѵٰ� �����ض�)



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