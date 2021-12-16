// Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k

// We could use recursion to loop over the array for each number and determine if there are 2 after it that are greater

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find3Numbers(vector<int>& arr, int N) {

    vector<int> largeArr(N, INT_MIN);
    int minValue = INT_MAX;
    int largeValue;

    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            largeValue = arr[i+1];
            largeArr[i+1] = arr[i+1];
        } else {
            largeArr[i+1] = largeValue;
        }
    }

    for (int i = 1; i < N; i++) {
        minValue = min(arr[i-1], minValue);

        if (minValue < arr[i] && arr[i] < largeArr[i+1]) {
            return {minValue, arr[i], largeArr[i+1]};
        }
    }

    return {};
}

void printVector(vector<int>& ans) {
    for (auto i : ans) {
        cout << i << " ";
    }
}

int main() {
    vector<int> arr{1, 2, 1, 1, 3};
    int N = 5;

    vector<int> ans = find3Numbers(arr, N);
    printVector(ans);
}