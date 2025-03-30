#include <iostream>
#include <algorithm>

using namespace std;

int getGcdIter(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {

    int n, s;
    int gcd = 1;

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int a, dis;
        cin >> a;

        if (s - a > 0) {
            dis = s - a;
        }
        else {
            dis = a - s;
        }
        if (gcd != 1) {
            gcd = getGcdIter(a, dis);
        }
        else {
            gcd = dis;
        }
    }
    cout << gcd;
}