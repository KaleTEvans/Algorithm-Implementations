/*
    Given two sorted arrays A and B of size M and N respectively. Each array contains only distinct elements but may have some elements in common with the other array. 
    Find the maximum sum of a path from the beginning of any array to the end of any of the two arrays. We can switch from one array to another array only at the common elements.
    Note: Only one repeated value is considered in the valid path sum.
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxPathSum(int A[], int B[], int l1, int l2) {
    int sumOne = 0;
    int sumTwo = 0;
    int maxSum = 0;
    int i = 0; 
    int j = 0;

    while (i < l1 && j < l2) {
        if (A[i] < B[j]) {
            sumOne += A[i];
            i++;
        } else if (A[i] > B[j]) {
            sumTwo += B[j];
            j++;
        } else if (A[i] == B[j]) {
            maxSum += max(sumOne, sumTwo) + A[i];
            sumOne = 0;
            sumTwo = 0;
            i++;
            j++;
        }
    }

    while (i < l1) {
        sumOne += A[i];
        i++;
    }

    while (j < l2) {
        sumTwo += B[j];
        j++;
    }

    return maxSum + max(sumOne, sumTwo);
}

int main() {
    int A[] = {2, 3, 7, 10, 12};
    int B[] = {1, 5, 7, 8};
    int l1 = 5;
    int l2 = 4;

    cout << maxPathSum(A, B, l1, l2) << endl;
}