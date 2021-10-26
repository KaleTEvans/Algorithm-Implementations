#include <iostream>
#include <vector>

using namespace std;

// Kane's algorithm can be used to calculate the maximum subarray
// The idea here is to find the local maximum, or the maximum subarray of the subsection we are currently looking at
// Rather than using a double for loop to calculate every possible subarray, we can determine if the next element would increase the local maximum
// The local maximumn at index i is the maximum of A[i] and the sum of A[i] and local maximum at index i-1

int FindLargestSubArray(vector<int>& arr) {
    int n = arr.size();
    int localMax = 0;
    int globalMax = INT_MIN; // Negative Infinity

    for (int i : arr) {
        localMax = max(i, i + localMax);

        if (localMax > globalMax) {
            globalMax = localMax;
        }
    }

    return globalMax;
}

int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << FindLargestSubArray(a) << endl;
}
