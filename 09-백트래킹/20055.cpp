#include <iostream>
#include <vector>
using namespace std;

int n, k;
int start, endi;
int arr[201];
int cnt = 0;
int phase = 1;
bool robot[201] = { false };
bool stop = false;
bool isFirst = true;

void beltRotate() {
	if (start == 0) {
		start = 2 * n - 1;
	}
	else {
		start--;
	}
	if (endi == 0) {
		endi = 2 * n - 1;
	}
	else {
		endi--;
	}
	if (robot[endi]) {
		robot[endi] = false;
	}
}

void moveRobot() {
	if (!isFirst) {
		int idx = endi;
		for (int i = 0; i < n - 1; i++) {
			int next = idx;

			if (idx == 0) {
				idx = 2 * n - 1;
			}
			else {
				idx--;
			}

			if (!robot[next] && robot[idx] && arr[next] > 0) {
				arr[next]--;
				if (arr[next] == 0) {
					cnt++;
					if (cnt >= k) {
						stop = true;
						break;
					}
				}
				robot[next] = true;
				robot[idx] = false;
			}
		}
		robot[endi] = false;
	}
}

void putRobot() {
	if (arr[start] > 0) {
		arr[start]--;
		if (arr[start] == 0) {
			cnt++;
			if (cnt >= k) {
				stop = true;
			}
		}
		robot[start] = true;
		isFirst = false;
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		cin >> arr[i];
	}

	start = 0;
	endi = n - 1;

	while (!stop) {
		beltRotate();
		moveRobot();
		putRobot();
		if (stop) {
			break;
		}
		phase++;
	}
	cout << phase;
}