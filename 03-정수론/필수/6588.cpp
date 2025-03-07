#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n, res, a = -1;

	while (true) {
		cin >> n;
		if (n == 0) break;

		for (int i = 2; i <= n; i++) {
			if (isPrime(i)) {
				a = n - i;
				cout << a << "\n";
				if (isPrime(a)) {
					res = a;
					break;
				}
			}
		}

		cout << n << " = " << n - a << " + " << a << "\n";
	}

	return 0;
}
