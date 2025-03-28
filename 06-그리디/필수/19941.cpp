#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    string input;
    vector<char> line;
    int cnt = 0;

    cin >> n >> k;
    cin >> input;

    line.assign(n, 0);

    for (int i = 0; i < n; i++) {
        line[i] = input[i];
    }

    for (int i = 0; i < n; i++) {
        if (line[i] != 'P') continue;

        for (int f = i - k; f <= i + k; f++) {
            if (f >= 0 && f < n && line[f] == 'H') {
                line[f] = 'N';
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
}