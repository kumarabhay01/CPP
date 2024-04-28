#include <iostream>
#include <unordered_set>
using namespace std;

long long findAppeal(const string& subStr) {
    long long appeal{};
    std::unordered_set<char> uniqueChars;
    for (char ch : subStr) {
        uniqueChars.insert(ch);
    }
    appeal = static_cast<long long>(uniqueChars.size());
    return appeal;
}

long long appealSum(string inputStr) {
    long long sumAppeal{};
    long strLen = static_cast<long>(inputStr.length());
    for (int i = 0; i < strLen; i++)
        for (int len = 1; len <= strLen - i; len++)
            sumAppeal += findAppeal(inputStr.substr(i, len));

    return sumAppeal;
}


    long long appealSum2(string s) {
        vector<int> last(26);
        long res = 0, n = static_cast<long>(s.size());
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i + 1;
            for (int j : last)
                res += j;
        }
        return res;
    }


int main() {
    string s = "abbca";
    //cout << "Appeal Sum : " << appealSum(s) << endl;
    cout << "Appeal Sum : " << appealSum2(s) << endl;
    return 0;
    }
