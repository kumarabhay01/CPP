#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int majorityElement(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        m[nums[i]]++;
    }
    n = n / 2;
    for (auto x : m) {
        if (x.second > n) {
            return x.first;
        }
    }
    return 0;
}

int main() {
    vector<int> nums{ 2,2,1,1,1,2,2 };
    cout << majorityElement(nums);
    return 0;
}
