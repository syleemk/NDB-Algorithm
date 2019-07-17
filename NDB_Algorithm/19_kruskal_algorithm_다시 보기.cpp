/*
	ũ�罺Į �˰����� ���� ���� ������� ��� ��带 �����ϱ� ���� ����ϴ� �˰���
	>> �ٽ� ���� �ּ� ��� ���� Ʈ���� ����� ���� ��ǥ�� �˰���

	���� �������� ���ð� ���� ��, �� ���ø� ���θ� �̿��� �����ϰ��� �� ��
	����� �ּ������� �ϰ��� �� ��, ������ ����Ǵ� �˰���


	* �ּҺ�� ����Ʈ���� �Ǳ� ���ؼ�
	������ �� = ����� �� - 1 
	�� �����ؾ��Ѵ�.

	ũ�罺Į �˰����� �ٽ� ������ 
	������ �Ÿ��� ª�� ������� �׷����� ���Խ�Ű�� ��

	�ϴ� ��� ��带 �ִ��� ���� ������� "���Ḹ" ��Ű�� �Ǳ� ������
	��� ���� ������ ������������ ������ �ڿ�
	����� ���� �������� �������� �׷����� ���Խ�Ű�� ��

	����Ŭ�� �߻��ϸ� �ȵ�!
	����Ŭ�� �߻� ���δ� union find �˰����� ����

	----------------------------------------------------------

	��� �������� �Ÿ�(���)�� �������� ���� �������� ���� ����

	1. ���ĵ� ������ �°� �׷����� ����
	2. ���Խ�Ű�� ���� ����Ŭ ���̺��� Ȯ��
	3. ����Ŭ�� �����ϴ� ��� ������ �������� ���� 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

//���� Ŭ���� ����
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator< (Edge &edge) {// ���ı��� 
		return this->distance < edge.distance; //�Ÿ��� ������ ����
	}

};

int main() {
	const int n = 7; //��� ��
	const int m = 11; //������ ��

	//���Ϳ��ٰ� ������ ���� �־��ִ� ��
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	//������ ����� �������� �������� ����
	sort(v.begin(), v.end());
	
	//�� ����(���)�� ���Ե� �׷����� ������� ����
	int parent[n];
	for (int i = 0; i < v.size; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//����Ŭ�� �߻����� �ʴ� ��� �׷����� ����
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1));

	}

}