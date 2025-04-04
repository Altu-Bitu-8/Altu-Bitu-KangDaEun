#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> dp;

int f(int n) {
    if (n <= 1) {
        return n;
    }
    if (dp[n]) {
        return dp[n];
    }
    return dp[n] = (f(n - 1) + f(n - 2)) % 10007;
}

int main()
{
    int n;

    cin >> n;

    dp.assign(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;

    cout << f(n);
}