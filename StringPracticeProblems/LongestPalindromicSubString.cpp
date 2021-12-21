// given string s, return the longest palindromic substring in s

#include <iostream>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
    int mid, left, right;
    int longest = INT_MIN;
    int finalLeft = INT_MIN;
    int finalRight = INT_MIN;

    if (s.size() <= 1) return s;
    
    for (int i=0; i < s.size(); i++) {
        mid = i+1;
        left = mid-1;
        if (s.size() > 2) {
            right = mid+1;
        }
        
        if (s[mid] == s[left]) {
            right = mid;
        } else if (s[mid] == s[right]) {
            left = mid - 1;
        }
        
        while (s[left] == s[right]) {
            if (right - left > longest) {
                longest = right - left;
                finalLeft = left;
                finalRight = right;
            }
            left++;
            right++;
        }
    }

    string ans;
    for (int i=finalLeft; i <= finalRight; i++) {
        ans.push_back(s[i]);
    }

    return ans;
}

int main() {
    string s = "ac";

    cout << longestPalindrome(s);
}