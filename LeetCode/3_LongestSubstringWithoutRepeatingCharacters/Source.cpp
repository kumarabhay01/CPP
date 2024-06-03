#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string str) {
	if (str.length() == 0)
		return 0;
	if (str.length() == 1)
		return 1;
	
	bool charSet[256]{ false };
	int maxLength = 0;
	int l_idx = 0,
		r_idx = 0;

	for (; r_idx < str.length(); r_idx++) {
		if (charSet[str[r_idx]] == false)
			charSet[str[r_idx]] = true;
		else {
			maxLength = max(maxLength, (r_idx - l_idx));

			while (l_idx < r_idx) {
				if (str[l_idx] != str[r_idx])
					charSet[str[l_idx]] = false;
				else {
					l_idx++;
					break;
				}
				l_idx++;
			}
		}
	}
	maxLength = max(maxLength, (r_idx - l_idx));
	return maxLength;
}

int main() {
	cout << "Max Length = " << lengthOfLongestSubstring("bbbbb");
	return 0;
}
