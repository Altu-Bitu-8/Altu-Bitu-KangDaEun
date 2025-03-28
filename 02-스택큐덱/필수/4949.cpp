#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;




int main()
{
	string s;


	while (true)
	{
		stack<char> stk;
		bool isNotPair = false;
		getline(cin, s);

		if (s[0] == '.' && s.length() == 1) break;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[') {
				stk.push(s[i]);
			}
			else if (s[i] == ')') {
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else {
					isNotPair = true;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!stk.empty() && stk.top() == '[') stk.pop();
				else {
					isNotPair = true;
					break;
				}
			}
		}

		if (isNotPair == false && stk.empty()) cout << "yes\n";
		else cout << "no\n";
		while (!stk.empty()) stk.pop();
	}



}