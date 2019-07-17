/*
	union find(������ ã��) �˰����� ��ǥ���� �׷��� �˰���
	���μ� ����(Disjoint Set) �˰����̶�� �θ���.
	�������� ã�� ���� ���μҸ� ã�� ��, �ٽø��ؼ� ���� ���� ������ �ƴ� ���� ã�� �Ͱ� ���Ƽ�
	�̷��Ե� �θ��� ��.

	�������� ��尡 ������ ��, �ΰ��� ��带 �����ؼ� 
	���� �� �� ��尡 ���� ���� �׷����� ���ϴ��� �Ǻ��ϴ� �׷��� �˰���

	���߿� ��� �˰��� ������� ���̴� �����Ƿ� Ȯ���� ����!
	>> ũ�罺Į �˰��� ��..

	������ �ϳ��� �������� ������ �������� ��尡 �ִ�

	���δٸ� ��带 ��ĥ��(union) �Ϲ������� �� ���� ���� �θ��尡 �ǵ��� ��ģ��.

	1-2-3 ���ʷ� ����� ��尡 ���� ��, 1�� 2�� ����ǰ� 2-3�� ����Ǿ�������
	ǥ�� ���� �� �� ������, 1�� 3�� ����Ǿ��ٴ� ����� �ٷ� �� �� ����

	��� 1,2,3�� �θ� ��� 1�̱� ������ �� ������ ���� ��� ���� �׷����� ���Ѵ� �� �� ����

	find �˰����� �� ���� ����� �θ��带 Ȯ���Ͽ�, ���� ���� ���տ� ���ϴ��� Ȯ���ϴ� �˰����̴�.

*/

#include <stdio.h>

//�θ��带 ã�� �Լ�
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

//�� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//���� �θ� �������� Ȯ�� (= ���� �׷����� �����ִ��� ���� �Ͱ� ����)
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i; //�⺻������ �ڱ��ڽ��� �θ�� ����Ű���� �������
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
}
