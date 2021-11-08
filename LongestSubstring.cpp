#include <iostream>
#include <set>

using namespace std;

// Algorithm to determine the length of the longest substring in a given string
// This can be solved using the sliding window approach

int LengthOfLongestSubstring(string s) {
    set<char> MySet;
    int CurrentCount = 0;
    int LargestCount = 0;

    for (int i=0; i < s.size(); i++) {
        if (MySet.find(s[i]) != MySet.end()) {
            MySet.clear(); 
            if (CurrentCount > LargestCount) {
                LargestCount = CurrentCount; 
            }
            CurrentCount = 0; 
        }
        MySet.insert(s[i]); 
        CurrentCount++; 
    }
    if (LargestCount > 1) {
        return LargestCount;
    } else {
        return CurrentCount;
    }
}

int main() {
    string s = " ";

    cout << LengthOfLongestSubstring(s) << endl;
}