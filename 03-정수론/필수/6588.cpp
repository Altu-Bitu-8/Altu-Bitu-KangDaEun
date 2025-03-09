#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int range = 1000000;
int primeNum[1000001] = { 0 };

void makePrime() {

	for (int i = 2; i <= sqrt(range); i++) {
		if (primeNum[i] == 0) {
			for (int j = i * i; j <= range; j += i) {
				primeNum[j] = 1;
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	makePrime();

	int a, n;


	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		bool isRight = false;

		for (int i = 3; i <= n; i += 2) {
			if (primeNum[i] == 0 && primeNum[n - i] == 0) {
				cout << n << " = " << i << " + " << n - i << "\n";
				isRight = true;
				break;
			}

		}
		if (!isRight) {
			cout << "Goldbach's conjecture is wrong.\n";
		}


	}


}
