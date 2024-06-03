#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    size_t n = nums.size();

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            return { numMap[complement], i };
        }
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}

vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    vector<int> returnValue;
    size_t length = nums.size();
    for (int i = 0; i <= length - 2; i++) {
        for (int j = i + 1; j <= length - 1; j++) {
            if (target == nums[i] + nums[j]) {
                returnValue.push_back(i);
                returnValue.push_back(j);
            }
        }
    }
    return returnValue;
}

int main() {

}
