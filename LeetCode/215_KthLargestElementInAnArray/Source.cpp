#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);

    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > min_heap.top()) {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    return min_heap.top();
}

int main(){
    vector<int> nums{ 3,2,1,5,6,4,8 };
    cout << findKthLargest(nums, 3);
    return 0;
}
