// C++ program to reverse a string
#include<iostream>
#include<stack>
using namespace std;

// Function to reverse words*/
void reverseWords(string s)
	{
	// temporary vector to store all words
	stack<string> tmp;
	string str = "";
	
	for (int i = 0; i < s.length(); i++) {

		// Check if we encounter space
		// push word(str) to vector
		// and make str NULL
		if (s[i] == ' ' && (i == 0 || i == s.length() - 1))
			continue;

		if (s[i] == ' ' && s[i-1] != ' ') {
			tmp.push(str);
			tmp.push(" ");
			str = "";
		}
		else if(s[i] != ' ')
			str += s[i];
	}

	// Last word remaining,add it to vector
	tmp.push(str);

	// Now print from last to first in vector
	while (!tmp.empty()) {
		cout << tmp.top();
		tmp.pop();
	}
}


	string reverseWords1(string s) {
		reverse(s.begin(), s.end());
		int n = s.size();
		int left = 0;
		int right = 0;
		int i = 0;
		while (i < n) {
			while (i < n && s[i] == ' ')i++;
			if (i == n)break; // to stop index going out of bounds
			while (i < n && s[i] != ' ') {
				s[right++] = s[i++];
			}
			reverse(s.begin() + left, s.begin() + right);
			s[right++] = ' ';
			left = right;
			i++;
		}
		s.resize(right - 1);
		return s;
	}

// Driver Code
int main()
{
	string s = "  i   like this program very much  ";
	reverseWords(s);
	return 0;
}
