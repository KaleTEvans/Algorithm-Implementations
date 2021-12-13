// The quick sort algorithm uses a divide and conquer algorithm
// The method begins with selecting a pivot point and using two incrementers, i and j, with j starting at infinity and i starting at the pivot point
// the pivot can be placed anywhere in the array, common practice is usually the beginning or end
// i will search for numbers that are larger than the pivot, j will search for numbers less than the pivot

/*
    Psuedocode for quickSort function:
    quickSort(arr[], low , high) {
        if (low < high) {
            (Pi is the partitioning index, arr[pi] is now at the right place)
            pi = partition(arr, low, high)

            quickSort(arr, low , pi-1) (before pi)
            quickSort(arr, pi+1, high) (after pi)
        }
    }
*/

/* 
    Psuedocode for partition algo. This function takes the first element as pivot, places the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
    
    partition(arr[], low, high) {
        pivot = arr[high];

        i = (low - 1) // Index of smaller element indicates the right position of pivot found

        for (j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++
                swap arr[i] and arr[j]
            }
        }

        swap arr[i+1] and arr[high]
        return (i+1)
    }
*/

#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = low - 1;
    int temp;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[10] = {3, 1, 5, 6, 23, 4, 9, 1, 10, 90};

    int low = 0;
    int high = 9;

    quickSort(arr, low, high);
    printArr(arr, high);
}
