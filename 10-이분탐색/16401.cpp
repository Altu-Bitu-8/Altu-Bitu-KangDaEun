#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int binarySearch(int n, int key, vector<int>& snacks) {
    int left = 1;
    int right = snacks[n - 1];
    int mid;

    int res = 0;

    // 키 값의 존재여부 구하기
    while (left <= right) {
        mid = (left + right) / 2;

        int kids = 0;

        for (int i = 0; i < n; i++) {
            kids += snacks[i] / mid;
        }
        if (kids < key) { // key 값이 배열의 중앙값보다 작을 때-> 더 작은 값 탐색
            right = mid - 1;
        }
        else {  // key 값이 배열의 중앙값보다 클때-> 더 큰 값 탐색
            res = mid;
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;

    cin >> m >> n;

    vector<int> snacks(n);

    for (int i = 0; i < n; i++) {
        cin >> snacks[i];
    }

    sort(snacks.begin(), snacks.end());

    cout << binarySearch(n, m, snacks);
}