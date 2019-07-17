/*
	���������� ���״�� �����ؼ� �����ϴ� ��

	������������ �����ϴ� ���, ���� ���� ���� "����"�ؼ� ���� ������ ������ ���


	10���� ���� �����ϴ� ���

	10 + 9 + 8 + ... + 1 
	=> N * (N+1) /2
	=> ��ǻ�Ϳ��� ����� ���ϰų� ����� ������ ���� N�� ���� �� ������ �̹��ϹǷ� �����Ѵ�.
	=> N * N
	=> O(N * N) : Ư�� �˰����� ����ð� �����ϰ� ǥ���ϴ� ���� '�� �� ǥ����̶� ��'
	Ư���˰��� �� ����ȸ�� �����ϰ� ǥ��

	��, ���������� �ð����⵵ O(N^2)
	10000���� ������ �����Ϸ��� �Ͼ������ �����ؾ���
	N^2�� ������ ���� ��ȿ������ �˰���

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