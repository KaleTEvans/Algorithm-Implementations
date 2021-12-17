// The binary search tree method only works on a sorted array
// To use the search, find the midpoint of the array and compare to the number you are searching for 
// If the number is equal to the midpoint, break the loop and return the index
// If the number is greater than the midpoint, split the array in half and only look at the left half now
// If the number is less than the midpoint, split the array and only look at the right half

#include <iostream>
#include <vector>

using namespace std; 

int binarySearch(int arr[], int left, int right, int n) {
    while (left <= right) {
        int midPoint = left + (right - left) / 2;
        if (arr[midPoint] == n) {
            return midPoint;
        } 
        else if (arr[midPoint] > n) {
            right = midPoint;
        }
        else {
            left = midPoint+1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 12, 14, 23, 34, 55, 65, 75, 78};
    int left = 0;
    int right = 9;
    int n = 75;

    cout << binarySearch(arr, left, right, n);
}