#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result{};
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i++) {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1])
                continue;

            int threeSum{};
            int l_idx = i + 1,
                r_idx = nums.size() - 1;
            while (l_idx < r_idx) {
                threeSum = a + nums[l_idx] + nums[r_idx];
                if (threeSum > 0)
                    r_idx--;
                else if (threeSum < 0)
                    l_idx++;
                else {
                    result.push_back(vector<int>{a, nums[l_idx], nums[r_idx]});
                    l_idx++;
                    while (nums[l_idx] == nums[l_idx - 1] && l_idx < r_idx)
                        l_idx++;
                }   
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> x{ 0, 0, 0 };
    vector<vector<int>> res = sol.threeSum(x);
}
