// Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise) by D steps, where D is a positive integer

/*
    Example:
    N= 5, D = 2
    arr[] = {1, 2, 3, 4, 5}

    Output: {3, 4, 5, 1, 2}
*/

// An O(n log(n)) solution would be to make this function recursive, with each function call doing a single rotation

#include <iostream>

using namespace std;

// increment value needs to be made global
int step = 0;

void printArr(int arr[], int n) {
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
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

int main() {
    int n = 11;
    int d = 6;

    int arr[] = {2, 62, 31, 79, 6, 21, 37, 45, 27, 23, 66};

    juggleAlgo(arr, d, n);
    printArr(arr, n);
}