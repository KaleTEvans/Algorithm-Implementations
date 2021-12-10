// given an array of size n of positive integers (which may have duplicates), find the maximum and second maximum values in the array. If no second max exists, return it as -1
// ex. [1,2,3,4,5] should return 4,5
// ex. [2,1,2] should return 2,1

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;

vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    
    /*********************************
     * Your code here
     * This function should return a
     * vector with first element as
     * max and second element as 
     * second max
     * *******************************/

    std::sort(arr, arr+sizeOfArray);
    max = arr[sizeOfArray-1];
    
    for (int i=sizeOfArray-2; i >= 0 ; i--) {
        max2 = arr[i];
        if (max2 == max) {
            continue;
        } else {
            break;
        }
    }

    if (max2 == INT_MIN || max2 == max) {
        max2 = -1;
    }

    cout << max << " " << max2;

    vector<int> largest{max, max2};
    
    return largest;
}

int main() {
    int sizeOfArray = 6;
    int arr[] = {10, 10, 10, 10, 10, 10};

    largestAndSecondLargest(sizeOfArray, arr);
}