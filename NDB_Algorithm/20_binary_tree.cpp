/*
	����Ʈ���� Ʈ�� �ڷᱸ���� Ȱ���� ��ǥ�� ���÷�
	�������� Ž���ӵ��� ������Ű�� ���� ����ϴ� ����

	������ Ʈ���� ����� �����ϱ� ���ؼ��� �����͸� ����ؾ��Ѵ�.

	����Ʈ������ Ž����� 3���� ����
	1.���� ��ȸ +ab
	2.���� ��ȸ a+b
	3.���� ��ȸ ab+ >> ������ ó���� �� ���� ����
*/

#include <iostream>

using namespace std;

const int number = 15;

// �ϳ��� ��� ������ ����
typedef struct node * treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

//���� ��ȸ
void preorder(treePointer ptr) {
	if (ptr) {//�ش� �����Ͱ� null�� �ƴ϶��
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//���� ��ȸ
void inorder(treePointer ptr) {
	if (ptr) {//�ش� �����Ͱ� null�� �ƴ϶��
		
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//���� ��ȸ
void postorder(treePointer ptr) {
	if (ptr) {//�ش� �����Ͱ� null�� �ƴ϶��
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	node nodes[number + 1];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	preorder(nodes + 1); puts("");
	inorder(nodes + 1); puts("");
	postorder(nodes + 1); puts("");

}