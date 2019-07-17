/*
	�� �� �̻��� ���ı����� ������ ���� ����
	�̶� pair�� ���� pair���
	pair�ȿ� pair�� ���� ����


	������ ������ 3���� �Ѿ�� �Ǹ�, pair�� �̿��ϴ°� ������ �� ������ �� ������
	�׶��� �׳� class �����ؼ� �ϴ°� �� ���� ���� �ִ�.
	
	���ı����� 2�� ������ ���� pair�� vector�� �̿��ؼ� ������ ���α׷��� �� �� �ִ�.
*/

#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<string, pair<int, int>> a,
	pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) { //������ ���ٸ�, ������ �� ��������� �켱����
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main(void) {
	//pair�ȿ� pair�� �� ���� ����
	vector <pair<string, pair<int, int>>> v; // ���ʴ�� �̸� ���� �������
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int >(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int >(97, 19930518)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int >(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int >(90, 19921207)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int >(88, 19900302)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}

	return 0;
}