#include<iostream>
#include<regex>
using namespace std;

bool isPalindrome(string s) {
    std::regex regex("[^a-zA-Z0-9]");
    auto str = std::regex_replace(s, regex, "");
    int fIdx = 0, lIdx = static_cast<int>(str.size()) - 1;
    while (fIdx < lIdx){
        if (tolower(str[fIdx]) != tolower(str[lIdx]))
            return false;

        fIdx++;
        lIdx--;
    }
    return true;
}


        bool isPalindrome2(string& s)
        {
            int i = 0, j = s.size() - 1;
            while (i < j)
                if (!isalnum(s[i]))
                    i++;
                else if (!isalnum(s[j]))
                    j--;
                else if (tolower(s[i]) != tolower(s[j]))
                    return false;
                else
                {
                    i++;
                    j--;
                }
            return true;
        }


int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
    return 0;
}
