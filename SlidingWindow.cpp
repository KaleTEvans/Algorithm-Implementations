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
        count = count + nums[i] - nums[i - 3];

        if (count > MaxCount) {
            MaxCount = count;
        }
    }
    return MaxCount;
}

// Here is an example for the variable size sliding window
// Suppose you are looking at a bookshelf with a set time to read, and want to read the most consecutive books
int VariableSizeSlidingWindow(vector<int>& nums, int MaxTime) {
    int MaxCount = 0;
    int count = 0;
    int R = 0;

    for (int i=0; i < nums.size(); i++) {
        if (i > 0) {
            count -= nums[i - 1];
        }
        while (R <= nums.size() && count + nums[R] <= MaxTime) {
            count += nums[R];
            R++;
        }
        MaxCount = max(count, R - i);
    }
    return MaxCount;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int MaxTime = 20;

    cout << FixedSizeSlidingWindow(nums, MaxTime) << endl;
}