#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int>> result{};

        for (int i = 0; i <= nums.size() - 3; i++) {
            int a = nums[i];

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
                }
            }
        }
        return result;
    }
};