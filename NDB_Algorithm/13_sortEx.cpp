#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

/*
//1181

bool compare(string a, string b) {//여기서 자기자신이 a가 되는 것임
	if (a.length() < b.length()) {// 자기자신을 다른 문자열과 비교해서 더짧으면 우선순위 높
		return 1;
	}
	else if (a.length() > b.length()) {// 길면 우선순위 낮
		return 0;
	}
	else {
		return a < b; // c++의 string같은 경우 비교연산자 넣어주면 자동으로 사전순으로 비교해줌
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

//범위 조건이 있는 경우 개수 정렬이 속도가 매우 빠르다!!
// 10000000개의 데이터를 연산하는 경우 NlogN을 해도 대략 2억번의 연산을 해야함

int countN[10001]; //= { 0, }; // 배열을 전역으로 선언하면, 프로그램 시작과 동시에 배열의 모든 원소가 0으로 초기화됨, 따로 초기화할 필요 x

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