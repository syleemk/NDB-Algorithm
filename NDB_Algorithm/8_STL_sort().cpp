/*
	���� �ð����� Ŭ������ �����Ͽ� �����ִ� �����͸� �����ϴ� ����� �˾ƺô�
	���� ���߿����� �ſ� ������ ���������, ���� �ڵ� �׽�Ʈ������ �ӵ��� �߿��ϹǷ� �������� ����

	Ŭ������ �̿��ϴ� ����� �ǹ��� ������ ���
	�Ϲ��� ���α׷��� ��ȸ�� ���� ���� ������ �ʿ��� ����
	���(pair)���̺귯���� ����ϴ� ���� ȿ�����̴�.
*/

#include <iostream>
#include <vector> // c++���α׷��� �ϸ� vector���̺귯�� ������ ���� ��� / �ܼ� �迭 �� ������, ���Ḯ��Ʈ ���·� ǥ���Ǵ� ���� �� �������� �ϴٺ��� �˰Ե�
//�ܼ� �迭�� ����(���Ḯ��Ʈ)�� ū ���� ���ٰ� �ϴ� ����
#include <algorithm>
#include <string>

using namespace std;

//vector�� ���Ҹ� ���������� ����(push) ����(pop) �� �� �ִ�, �迭�� ���� ����ϱ� ���� ������ �ڷᱸ��
int main(void) {
	vector <pair<int, string>> v; //���⼭ pair�� �� "��"�� ������ �ٷ�� ���� ����ϴ� ���̺귯��
	
	//vector�� ���� �ϳ��� ����Ʈ
	//push_back :����Ʈ�� ������ �κп� ����
	v.push_back(pair<int, string>(90, "�� �� ��"));
	v.push_back(pair<int, string>(85, "�� �� ��"));
	v.push_back(pair<int, string>(82, "�� �� ��"));
	v.push_back(pair<int, string>(98, "�� �� ��"));
	v.push_back(pair<int, string>(79, "�� �� ��"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}

	return 0;
}


