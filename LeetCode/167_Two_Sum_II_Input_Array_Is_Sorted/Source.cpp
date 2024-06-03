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
            return { numMap[complement], i+1 };
        }
        numMap[nums[i]] = i+1;
    }

    return {}; // No solution found
}

vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    vector<int> returnValue;
    int length = nums.size();
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

vector<int> twoPointerSolution(vector<int>& nums, int target) {
    vector<int> returnValue{};
    int l_idx = 0,
        r_idx = nums.size() - 1;

    while (l_idx < r_idx) {
        if (nums[l_idx] + nums[r_idx] == target)
        {
            returnValue.push_back(l_idx + 1);
            returnValue.push_back(r_idx + 1);
            return returnValue;
        }
        
        if (nums[l_idx] + nums[r_idx] < target)
            l_idx++;

        if (nums[l_idx] + nums[r_idx] > target)
            r_idx--;
    }
    return returnValue;
}


int main() {
    vector<int> vec{2, 7, 11, 15};
    vector<int> result = twoPointerSolution(vec,9);
    cout << "[" << result[0] << "," << result[1] << "]";
    return 0;
}
