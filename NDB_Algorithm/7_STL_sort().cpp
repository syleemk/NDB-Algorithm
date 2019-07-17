/*
	���� �˰��� ��ȸ���� ���Ĺ����� ������ ���� ������������ sort�Լ� ���

	sort�Լ��� ������ ��, �츮�� ���ı����� ������ �� ����

	�ǹ������� �������� ������ �����͸� �������� ����
	�ǹ������� ��� �����͵��� ��ü�� �����Ǿ� ���������� �������� ������ �����ϰ� �ֱ� ����
	�� ��� ���� �߿��� ���� ����� 'Ư���� ������ ��������' �����ϴ� ��
*/


#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) { // T F���� �������� ����
	return a > b; // �� ���� ���� ������ ���� ��
}

int main(void) {
	int a[10] = { 3,1,4,1,5,9,2,6,9,7 };
	sort(a, a + 10, compare); //���� �����ּҿ�, ������ �ּ� �־��ָ�, ���ۺ��� ������ �����ϸ� �Ǵ±��� �ϰ� ��������
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
	//���� ������ ������
	mergeSort(a, m, middle);
	mergeSort(a, middle + 1, n);
	merge(a, m, middle, n); // ��ĥ�� �����Ѵ�

}

int main() {
	int arr[num] = { 1,3,10,9,8,4,13,16 };
	mergeSort(arr, 0, num-1);

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
}

*/