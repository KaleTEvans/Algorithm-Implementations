// The sliding window algorithm can be useful for solving array and string algorithms
#include <iostream>
#include <vector>

using namespace std;

// An example use case for the fixed size sliding window is to find the largest sum of a given consecutive values in an array
int FixedSizeSlidingWindow(vector<int>& nums, int window) {
    int count = 0;
    int MaxCount = 0;

    for (int i=0; i < window; i++) {
        count += nums[i];
    }

    for (int i=window; i < nums.size(); i++) {
        count = count + nums[i] - nums[i - window];

        if (count > MaxCount) {
            MaxCount = count;
        }
    }
    return MaxCount;
}

// Here is an example for the variable size sliding window
// find the maximum sum of any contiguous subarray of size k
int VariableSizeSlidingWindow(vector<int>& nums, int k) {
    
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int MaxTime = 20;

    cout << VariableSizeSlidingWindow(nums, MaxTime) << endl;
}