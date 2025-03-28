#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    vector<long long> speed;
    int num = 1;

    cin >> n;

    speed.assign(n, 0);

    long long ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        cin >> speed[i];
    }


    for (int i = 0; i < n; i++) {
        if (ans <= speed[i]) ans = max(ans, speed[i]);
        else if (ans % speed[i] == 0) continue;
        else ans = (ans / speed[i] + 1) * speed[i];
    }

    cout << ans;
}