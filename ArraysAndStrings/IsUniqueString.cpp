// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

// The first thing that would come to mind here would be to add characters to a set, and if the set already contains a character, return false

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using std::cin;
using std::cout;
using std::string;

bool isUniqueSet(string &s) {
    std::unordered_set<char> newSet;
    std::unordered_set<char>::iterator it;

    for (int i; i < s.size(); i++) {
        it = newSet.find(s[i]);

        if (it != newSet.end()) {
            return false;
        }

        newSet.insert(s[i]);
    }

    return true;
}

// Now, we need to determine this without the set data structure
// We could do this using brute force by comparing every element of the string to other elements
// Another method would be to sort the string so that we only have to loop through it once
bool isUniqueSort(string &s) {
    std::sort(s.begin(), s.end());

    for (int i=0; i < s.size(); i++) {
        if (s[i] == s[i-1]) return false;
    }

    return true;
}

int main() {
    string s = "iamstring";

    cout << isUniqueSort(s) << std::endl;
}