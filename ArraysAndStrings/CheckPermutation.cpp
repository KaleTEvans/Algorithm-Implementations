// Given two strings, write a method to decide if one is a permutation of the other
// A permutation is two words that have the same letters, but in a different order

// a quick and easy method here would be to sort both of the strings and then compare them side by side

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using std::cout;
using std::cin;
using std::string;

bool isPermutationSort(string &s1, string &s2) {
    if (s1.size() != s2.size()) return false;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    for (int i=0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) return false;
    }

    return true;
}

int main() {
    string s1 = "hello";
    string s2 = "elloh";

    cout << isPermutationMap(s1, s2) << std::endl;
}