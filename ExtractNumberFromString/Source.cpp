//{ Driver Code Starts
// Initial Template for C++

#include<iostream>
#include <string>
#include<regex>
using namespace std;

class Solution {
public:
    long long ExtractNumber(string sentence) {
        //regex regex("\\S+");
        regex regex("\\d+");
        smatch match;
        string s = sentence;
        vector<string> numbers;
    
        while (regex_search(s, match, regex)) {
            numbers.push_back(match.str());
            s = match.suffix().str();
        }
    
        long long ans = -1;
        long long lens = LLONG_MIN;
    
        for (const auto& num : numbers) {
            if (num.find('9') == string::npos) {
                long long numValue = stoll(num);
                if (lens < numValue) {
                    ans = numValue;
                    lens = numValue;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {


    string s = "This is alpha 5057 and 97";
    Solution ob;
    cout << ob.ExtractNumber(s) << "\n";
    return 0;
}