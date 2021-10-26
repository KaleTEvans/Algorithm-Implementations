#include <iostream>
#include <vector>

using namespace std;

// slightly simplified version of Kadane's algorithm

int MaxSubArray(vector<int> &a) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < a.size(); i++) {
        currentSum += a[i];

        maxSum = max(currentSum, maxSum);
        // if the currentsum is negative reset the value to see if next number is larger
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main() {
    vector<int> a = {-1, -1, -1};

    cout << MaxSubArray(a) << endl;
}