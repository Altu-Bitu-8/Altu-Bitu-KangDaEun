#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 라이브코딩 문제와 유사한것 같아 코드를 참고했습니다. 근데 코드는 다 이해했어요.

int main()
{
    int n, len;
    int max_len = 0;
    int max_idx = -1;
    int a[1001], dp[1001];
    vector<int> arr;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        len = 0;

        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                len = max(dp[j], len);
            }
        }
        dp[i] = len + 1;

        if (max_len < dp[i]) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    for (int i = max_idx; i >= 0; i--) {
        if (max_len == dp[i]) {
            arr.push_back(a[i]);
            max_len--;
        }
    }

    int size = arr.size();
    cout << size << "\n";
}