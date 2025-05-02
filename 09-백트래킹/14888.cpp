#include <iostream>
using namespace std;

int n;
int arr[11];
int oper[4];
int thisMax = -1000000001;
int thisMin = 1000000001;

void backtracking(int result, int idx) {

	if (idx == n) {
		if (thisMax < result) {
			thisMax = result;
		}
		if (thisMin > result) {
			thisMin = result;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;

			if (i == 0) {
				backtracking(arr[idx] + result, idx + 1);
			}
			else if (i == 1) {
				backtracking(result - arr[idx], idx + 1);
			}
			else if (i == 2) {
				backtracking(result * arr[idx], idx + 1);
			}
			else {
				backtracking(result / arr[idx], idx + 1);
			}

			oper[i]++;
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	backtracking(arr[0], 1);

	cout << thisMax << "\n";
	cout << thisMin;
}