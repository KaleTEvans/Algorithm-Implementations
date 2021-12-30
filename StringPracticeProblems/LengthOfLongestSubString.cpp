// Given a string s, find the length of the longest substring without repeating characters

#include <iostream>
#include <unordered_set>

using namespace std;

// The function uses a sliding window approach, with the leading end searching until a duplicate is found, and then incrementing the tail end

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int i = 0;
    int j = 0;
    int maxCount = 0;
    
    while (i < s.size() && j < s.size()) {
        if (set.find(s[j]) == set.end()) {
            set.insert(s[j]);
            j++;
            maxCount = max(j-i, maxCount);
        } else {
            set.erase(s[i]);
            i++;
        }
    }

    return maxCount;
    
}

int main() {
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s);
}