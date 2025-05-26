#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

void go(int start, int end) {
    if (start >= end) return;
    if (start == end - 1) {
        cout << v[start] << '\n';
        return;
    }
    int idx = start + 1;
    while (idx < end) {
        if (v[start] < v[idx]) break;
        idx++;
    }
    go(start + 1, idx);
    go(idx, end);
    cout << v[start] << '\n';
    return;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    while (cin >> n) {
        v.push_back(n);
    }
    go(0, v.size());

}