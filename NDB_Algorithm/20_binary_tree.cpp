/*
	이진트리는 트리 자료구조를 활용한 대표적 예시로
	데이터의 탐색속도를 증진시키기 위해 사용하는 구조

	실제로 트리를 제대로 구현하기 위해서는 포인터를 사용해야한다.

	이진트리에서 탐색방법 3가지 있음
	1.전위 순회 +ab
	2.중위 순회 a+b
	3.후위 순회 ab+ >> 수식을 처리할 때 많이 쓰임
*/

#include <iostream>

using namespace std;

const int number = 15;

// 하나의 노드 정보를 선언
typedef struct node * treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

//전위 순회
void preorder(treePointer ptr) {
	if (ptr) {//해당 포인터가 null이 아니라면
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//중위 순회
void inorder(treePointer ptr) {
	if (ptr) {//해당 포인터가 null이 아니라면
		
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//후위 순회
void postorder(treePointer ptr) {
	if (ptr) {//해당 포인터가 null이 아니라면
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