#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int SumDigit(string serialCode) {
    int total = 0;

    for (int i = 0; i < serialCode.length(); i++) {
        if (isdigit(serialCode[i])) {
            total += serialCode[i] - '0';
        }
    }
    return total;
}

bool cmp(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    if (SumDigit(s1) != SumDigit(s2)) {
        return SumDigit(s1) < SumDigit(s2);
    }
    return s1 < s2;
}



int main() {
    int n;

    cin >> n;

    vector<string> serial(n);

    for (int i = 0; i < n; i++) {
        cin >> serial[i];
    }
    sort(serial.begin(), serial.end(), cmp);
    for (int i = 0; i < serial.size(); i++) {
        cout << serial[i] << "\n";
    }
}