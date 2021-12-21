// Given an array of size N, find the largest sum of values in the array where no values are adjacent to each other

// Ex, [1, 2, 3, 4, 5] would be 9, or 1+3+5

// As you loop through the array, track two sums, exclusive and inclusive. 
// the inclusive value is the sum of the previous exlusive value and the current element
// the exclusive value is the maximum of the previous inclusive value and the previous exclusive value, and begins at 0

#include <iostream>
#include <algorithm>

using namespace std;

int total = 0;

int maxNonAdjacentSum (int n, int arr[]) {

    int inclusive = arr[0];
    int exclusive = 0;
    int currentExcl;

    for (int i=1; i < n; i++) { 
        currentExcl = max(inclusive, exclusive);
        inclusive = exclusive + arr[i];
        exclusive = currentExcl;
    }

    return max(inclusive, exclusive);
}

int main() {
    int arr[] = {5, 3, 4, 11, 2};
    int n = 5;

    cout << maxNonAdjacentSum(n, arr);
}