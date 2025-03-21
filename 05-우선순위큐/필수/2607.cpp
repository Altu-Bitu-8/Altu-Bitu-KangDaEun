#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

// 정말 죄송하지만 도저히 모르겠어서 틀린 상태로 제출합니다... 죄송해요...

map<char, int> makeMap(const string& s) {
	map<char, int> mp;
	for (char c : s) {
		mp[c]++;
	}
	return mp;
}

bool isOneDiff(const map<char, int>& big, const map<char, int>& small) {
	int chk = 0;
	for (auto& ent : big) {
		char c = ent.first;
		int countBig = ent.second;
		int countSmall = small.count(c);

		if (countBig - countSmall == 1) {
			chk++;
		}
		else {
			return false;
		}
	}


	if (chk == 1) return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<char, int> st;
	string str, cmp;
	int n;
	int check = 0;

	cin >> n;

	cin >> str;

	st = makeMap(str);

	for (int i = 1; i < n; i++) {

		cin >> cmp;

		map<char, int> cp = makeMap(cmp);

		if (str.size() == cmp.size() && cp == st) {
			check++;
			cout << "1\n";
			continue;
		}

		if (str.size() - cmp.size() == -1) {
			if (isOneDiff(cp, st)) {
				check++;
				cout << "2\n";
				continue;
			}
		}

		if (str.size() - cmp.size() == 1) {
			if (isOneDiff(st, cp)) {
				check++;
				cout << "3\n";
				continue;
			}
		}


	}
	cout << check;
}
