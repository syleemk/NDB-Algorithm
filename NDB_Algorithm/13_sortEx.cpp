#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

/*
//1181

bool compare(string a, string b) {//���⼭ �ڱ��ڽ��� a�� �Ǵ� ����
	if (a.length() < b.length()) {// �ڱ��ڽ��� �ٸ� ���ڿ��� ���ؼ� ��ª���� �켱���� ��
		return 1;
	}
	else if (a.length() > b.length()) {// ��� �켱���� ��
		return 0;
	}
	else {
		return a < b; // c++�� string���� ��� �񱳿����� �־��ָ� �ڵ����� ���������� ������
	}
}

string arr[20000];


int main() {
	int n;
	int print =1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) continue;
		else cout << arr[i] << endl;
	}
}

*/

/*
// 1431

string arr[1000];

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
			sum += a[i] - '0';
	}
	return sum;
}

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		if (aSum != bSum) return aSum < bSum;
		else return a < b;
	}
}


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

}
*/


//10989

//���� ������ �ִ� ��� ���� ������ �ӵ��� �ſ� ������!!
// 10000000���� �����͸� �����ϴ� ��� NlogN�� �ص� �뷫 2����� ������ �ؾ���

int countN[10001]; //= { 0, }; // �迭�� �������� �����ϸ�, ���α׷� ���۰� ���ÿ� �迭�� ��� ���Ұ� 0���� �ʱ�ȭ��, ���� �ʱ�ȭ�� �ʿ� x

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int x;
		scanf("%d", &x);
		countN[x]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < countN[i]; j++) {
			cout << i << '\n';
		}
	}
}