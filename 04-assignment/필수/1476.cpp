#include <iostream>
#include <string>

using namespace std;



int main()
{
    int e, s, m;
    int ans = 0;

    cin >> e >> s >> m;


    for (int i = 1; i < 7981; i++) {
        if (i % 15 == e % 15 && i % 28 == s % 28 && i % 19 == m % 19) {
            ans = i;
            break;
        }
    }
    cout << ans;
}

