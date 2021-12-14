// Given an array A of N elements, Find the minimum index based difference between two elements of the array, X and Y. If no distance exists return -1
/*
    Ex. A = [1, 2, 3, 2]
    X = 1, Y = 2

    Output would be 1
    the two distances would be 1 and 3, 1 being the smallest
*/

#include <iostream>
#include <algorithm>

using namespace std;

int minDist(int a[], int n, int x, int y) {
    // variables to hold index values and distance
    int indexX = INT_MIN;
    int indexY = INT_MIN;
    int distance = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            indexX = i;
            cout << indexX << endl;
        }
        if (a[i] == y) {
            indexY = i;
            cout << indexY << endl;
        }
        if (indexY != INT_MIN && indexX != INT_MIN) {
            distance = min(distance, abs(indexY - indexX));
        }
    }

    if (indexX == INT_MIN || indexY == INT_MIN) {
        return -1;
    } else {
        return distance;
    }
}

int main() {
    int n = 2;
    int a[] = {1, 2};
    int x = 1;
    int y = 2;

    cout << minDist(a, n, x, y);
}