// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t 
// (including duplicates) is included in the window. If there is no such substring, return the empty string "".

#include <iostream>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> m;
    
    int maxLength = 0;
    
    string maxString;
    
    for (int i=0; i < t.size(); i++) {
        m[t[i]]++;
    }

    for (auto i : m) {
        //cout << i.first << " " << i.second << endl;
    }
    
    for (int i=0; i < s.size(); i++) {
        if (m.find(s[i]) != m.end()) {
            int j = i;
            string curString = "";
            int curLength = 0;
            while (m.size() > 0) {
                if (j >= s.size()) break;
                curString.push_back(s[j]);
                if (m.find(s[j]) != m.end()) {
                    m.erase(s[j]);
                }
                j++;
                curLength++;
            }
            if (maxLength < curLength) {
                maxLength = curLength;
                maxString = curString;
                for (int i=0; i < t.size(); i++) {
                    m[t[i]]++;
                }
            }
        }
    }
    cout << maxString << endl;
    return maxString;
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    minWindow(s, t);
}