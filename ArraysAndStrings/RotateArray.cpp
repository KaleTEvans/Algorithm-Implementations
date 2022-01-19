// Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise) by D steps, where D is a positive integer

/*
    Example:
    N= 5, D = 2
    arr[] = {1, 2, 3, 4, 5}

    Output: {3, 4, 5, 1, 2}
*/

// An O(n log(n)) solution would be to make this function recursive, with each function call doing a single rotation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// increment value needs to be made global
int step = 0;

void printArr(int arr[], int n) {
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void printVector(vector<int>& v) {
    for (int i: v) {
        cout << i << " ";
    }
}

void rotateArr(int arr[], int d, int n) {

    if (step < d) {
        int temp = arr[0];

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                arr[i] = temp;
            } else {
                arr[i] = arr[i+1];
            }
        }

        step++;
        rotateArr(arr, d, n);
    }
}

// The juggling algorithm is a way to complete an array rotation with O(n) time complexity
// By finding the greatest common divisor (GCD) of the length of the array and the amount of rotations, this determines how we split the array into blocks to rotate

/*
    Number of sets will depend on the value of n and k, n being length of array and k being number of steps
    number of sets = gcd(n, k)
    Outer loop: i = 0 to i < number of sets
    A[j] = A[(j+k) % n] 
    Inner loop ends when d == i
    increment i by one to move to the next set
*/

int gcd(int a, int b) {
    if (b == 0) {
        cout << a << endl;
        return a;
    } else {
        return gcd(b, a%b);
    }
}

void juggleAlgo(int arr[], int k, int n) {
    int d = -1;
    int i, temp, j;

    for (i=0; i < gcd(n,k); i++) { // outer loop    
        j = i;
        temp = arr[i];

        while(1) { // inner loop
            d = (j + k) % n;

            if (d == i) break;

            arr[j] = arr[d];
            j = d;
        }
        arr[j] = temp;
    }
}

// For a right rotation, there is a very quick way. Begin by reversing the whole array. Find the modulo of the rotation amount and the array length
// Split the array at the modulo, reverse the first half, and then the second half

void rightRotation(vector<int>& v, int k, int n) {
    reverse(v.begin(), v.end());
    int j = k % n;

    reverse(v.begin(), v.begin()+j);
    // now reverse the rest of the vector
    reverse(v.begin()+j, v.end());
}

int main() {
    int n = 11;
    int d = 6;
    int k = 4;

    int arr[] = {2, 62, 31, 79, 6, 21, 37, 45, 27, 23, 66};
    vector<int> v = {2, 62, 31, 79, 6, 21, 37, 45, 27, 23, 66};

    rightRotation(v, k, n);
    printVector(v);
}