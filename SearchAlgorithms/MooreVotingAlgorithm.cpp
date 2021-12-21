// Given an array of length N, find the majority element that appears more times than N/2. If no such element exists, return -1

#include <iostream>
#include <algorithm>

using namespace std;

int majorityElement(int a[], int size) {
    int ele = INT_MIN;
    int count = 0;
    // loop through the array to determine which number appears the most
    for (int i=0; i < size; i++) {
        if (count == 0) {
            ele = a[i];
            count = 1;
        } else if (ele == a[i]) {
            count++;
        } else {
            count--;
        }
    }
    // now loop back over the array to get the correct count of the number
    count = 0;
    for (int i=0; i < size; i++) {
        if (a[i] == ele) {
            count++;
        }
    }
    // if the number is larger than half the size, then that is the answer
    if (count > size/2) {
        return ele;
    } else {
        return -1;
    }
}

int main() {
    int a[] = {3, 1, 3, 3, 4, 5, 5, 5, 5, 5, 5};
    int size = 11;

    cout << majorityElement(a, size);
}