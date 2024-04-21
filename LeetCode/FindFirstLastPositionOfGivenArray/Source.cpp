#include <iostream>
#include <vector>

using namespace std;

// Function to find the leftmost occurrence of the target element
size_t findFirstOccurrence(vector<int>& nums, int target) {
    size_t low = 0, high = nums.size() - 1;
    size_t firstOccurrence = -1;

    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            firstOccurrence = mid;
            high = mid - 1; // Search in the left half
        }
        else {
            low = mid + 1;
        }
    }

    return firstOccurrence;
}

// Function to find the rightmost occurrence of the target element
size_t findLastOccurrence(vector<int>& nums, int target) {
    size_t low = 0, high = nums.size() - 1;
    size_t lastOccurrence = -1;

    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (nums[mid] <= target) {
            lastOccurrence = mid;
            low = mid + 1; // Search in the right half
        }
        else {
            high = mid - 1;
        }
    }

    return lastOccurrence;
}

int main() {
    vector<int> nums = { 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    int target = 3;

    size_t firstOccurrence = findFirstOccurrence(nums, target);
    size_t lastOccurrence = findLastOccurrence(nums, target);

    cout << "First Occurrence: " << firstOccurrence << endl;
    cout << "Last Occurrence: " << lastOccurrence << endl;

    return 0;
}
