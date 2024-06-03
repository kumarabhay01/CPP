#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string res{};
        int pLength{};
        for (int i = 0; i < s.length(); i++) {
            //For Odd Palindrom
            int r_idx{ i }, l_idx{ i };
            while (l_idx >= 0 && r_idx < s.length() && s[l_idx] == s[r_idx]) {
                if ((r_idx - l_idx + 1) > res.length()) {
                    pLength = r_idx - l_idx + 1;
                    res = s.substr(l_idx, pLength);
                }
                r_idx++; l_idx--;
            }

            //For Even Palindrom
            l_idx = i, r_idx = i + 1;
            while (l_idx >= 0 && r_idx < s.length() && s[l_idx] == s[r_idx]) {
                if ((r_idx - l_idx + 1) > res.length()) {
                    pLength = r_idx - l_idx + 1;
                    res = s.substr(l_idx, pLength);
                }
                r_idx++; l_idx--;
            }
        }
        return res;
    }
};

int main() {
    Solution solutionObj;
    string str = { "babad"};
    cout << "String : " << solutionObj.longestPalindrome(str);
    return 0;
}
