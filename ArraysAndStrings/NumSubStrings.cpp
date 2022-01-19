// Given a string s and an integer k, return the number of substrings of length k with no repeated characters

#include <iostream>
#include <unordered_set>

using namespace std;

int numKLenSubstrNoRepeats(string s, int k) {
    int count = 0;
    unordered_set<char> set;
    
    if (k > s.size()) return 0;
    
    for (int i=0; i <= s.size() - k; i++) {
        int j = i;
        int window = k + i - 1;
        cout << j << " " << window << endl;
        while (j <= window) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j]);
            } else {
                set.clear();
                break;
            }
            j++;
        }
        if (set.size() == k) {
            count++;
            set.clear();
        }
        
        cout << count << endl;
    }
    
    return count;
}

int main() {
    string s = "havefunonleetcode";
    int k = 5;

    cout << numKLenSubstrNoRepeats(s, k);
}