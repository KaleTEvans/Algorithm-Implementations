// Merge sort is a divide and conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves
// The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted subarrays into one

/*
    MergeSort(arr[], 1, r)
    if r > 1
        1. Find the middle point to divide the array into two halves:
            middle m = 1 + (r-1)/2
        2. Call mergesort for the first half:
            Call mergesort(arr, 1, m)
        3. Call mergeSort for second half:
            Call mergeSort(arr, m+1, r)
        4. Merge the two halves sorted in step 2 and 3:
            Call merge(arr, l, m, r)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int begin, int end);
void printArray(int arr[], int n);

int main() {

    int arr[5] = {4,1,3,5,6};
    int begin = 0;
    int end = 4;

    mergeSort(arr, begin, end);
    printArray(arr, end);

    return 0;
}

void printArray(int arr[], int n) {
    for (int i=0; i <= n; i++) {
        cout << arr[i] << " ";
    }
}

// merge function, a little trickier to follow
void merge(int arr[], int left, int mid, int right) {

    // create temp array
    int temp[right + 1] = {0};

    // index for arrOne and arrTwo and full arr
    int i1 = left;
    int i2 = mid + 1;
    int k = left;
    
    while (i1 <= mid && i2 <= right) {
        if (arr[i1] <= arr[i2]) {
            temp[k] = arr[i1];
            i1++;
            k++;
        } else {
            temp[k] = arr[i2];
            i2++;
            k++;
        }
    }

    while (i1 <= mid) {
        temp[k] = arr[i1];
        i1++;
        k++;
    }

    while (i2 <= right) {
        temp[k] = arr[i2];
        i2++;
        k++;
    }

    // now set the original array values equal to the temp values
    for (int i=left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// merge sort function as described above
void mergeSort(int arr[], int begin, int end) {

    int mid;
    // if statement to decide to run the function or not
    if (begin < end) {
        //find the midpoint of the array and set variables 
        mid = (begin + end)/2;

        // recursive call for first half
        mergeSort(arr, begin, mid);
        // now for the second half
        mergeSort(arr, mid+1, end);
        // now call the merge function
        merge(arr, begin, mid, end);
    }

    return;
}
