// Given an array consisting only of prime numbers, remove all duplicate numbers from it

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> removeDuplicate(vector<int>& arr, int n)
{
    unordered_set<int> mySet;
    vector<int> newVector;
    
    for (int i=0; i < n; i++) {
        if (mySet.find(arr[i]) == mySet.end()) {
            mySet.insert(arr[i]);
            newVector.push_back(arr[i]);
        }
    }
    
    return newVector;
}

int main() {
    vector<int> arr{2, 2, 3, 3, 7, 5};
    int n = 6;

    removeDuplicate(arr, n);
}