#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b, result;

void Sum(int a, int b, int idx) {
    int c = a + b + (result[idx] - '0');
    int carry = c / 10;
    int x = c % 10;

    result[idx] = (char)(x + '0');
    if (carry > 0) {
        result[idx + 1] += carry; // ���� �ڸ��� ĳ�� �߰�
    }
}

int main() {
    cin >> a >> b;

    int aLen = a.length();
    int bLen = b.length();
    int maxLen = max(aLen, bLen);

    // ��� ���ڿ��� 0���� �ʱ�ȭ
    result = string(maxLen + 1, '0');

    for (int i = 0; i < maxLen; i++) {
        int digitA = (aLen - i - 1 >= 0) ? (a[aLen - i - 1] - '0') : 0;
        int digitB = (bLen - i - 1 >= 0) ? (b[bLen - i - 1] - '0') : 0;

        Sum(digitA, digitB, i);
    }

    // ���� ���� ���ڸ��� '0'�̸� ����
    if (result[maxLen] == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    cout << result;

}
