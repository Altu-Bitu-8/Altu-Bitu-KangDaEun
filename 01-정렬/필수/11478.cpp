#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

string Split(string S, int i, int j)
{
	return S.substr(i, j);

}

int main()
{
	string S;
	cin >> S;
	set<string> part;

	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < S.length(); j++) {
			part.insert(Split(S, i, j));
		}
	}
	cout << part.size();
}



