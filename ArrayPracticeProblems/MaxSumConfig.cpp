// Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. 
// The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

// Ex. Input N = 4, A[] = {8, 3, 1, 2}
// Output would be 29, the max sum is 3(0) + 1(1) + 2(2) + 8(3)

// To solve this, the idea would be to compute the value of a rotation using the values of the previous rotation
// This can be done without needing to sum up each rotation and compare them
/*
    When an array is rotated by one, the following changes happen in the sum of i*arr[i]
        1. Multiplier of arr[i-1] changes from 0 to n-1, ie, arr[i-1]*(n-1) is added to current value
        2. Multipliers of other terms is decremented by 1. (sum - arr[i-1]) is subtracted from current value
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int max_sum(int A[], int N) {
    int sum = 0;
    int totalSum = 0;
    int maxSum = INT_MIN;

    // get initial sum
    for (int i=0; i < N; i++) {
        sum += A[i];
        totalSum += A[i] * i;
    }

    for (int i=0; i < N; i++) {
        totalSum = totalSum + sum - N*(A[N-1-i]);
        maxSum = max(maxSum, totalSum);
    }

    return maxSum;
}

int main() {
    int A[] = {8, 3, 1, 2};
    int N = 4;

    cout << max_sum(A, N);
}