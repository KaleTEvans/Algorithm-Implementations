// Given an array of n integers, return true if there is a group of 3 values that has a sum of 0

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findTriplets(int arr[], int n) {
    // insert all values into a map
    // we can then use a double for loop and check if the sums of any two values has a counterpart in the map
    unordered_map<int, int> myMap;

    for (int i = 0; i < n; i++) {
        myMap.insert({arr[i], i});
    }

    int temp;

    for (int i=0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            temp = (arr[i] + arr[j]) * -1;
            //cout << temp << endl;
            if (myMap.find(temp) != myMap.end() && temp != arr[i] && temp != arr[j]) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int arr[] = {63, -30, 4, -33, 85, -6, 11};
    int n = 7;

    cout << findTriplets(arr, n);
}