// Given a string, write a function to check if it is a permutation of a palindrome. The palindrome does not need to be limited to just dictionary words

/*
    EXAMPLE
    input: Tact Coa
    output: True, (permutations: "taco cat", "atco cta")
*/

// One approach would be to put letters in a set and remove them if a pair is found. At the end, the set should either have 0 or 1 items left

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;

bool CheckPermutation(string &str) {
    std::unordered_set<char> mySet;

    // change all letters to lowercase
    std::for_each(str.begin(), str.end(), [](char & c) {
        c = ::tolower(c);
    });

    for (int i=0; i < str.size(); i++) {
        // skip over spaces
        if (str[i] == ' ') continue;

        if (mySet.find(str[i]) != mySet.end()) {
            mySet.erase(str[i]);
            continue;
        }

        mySet.insert(str[i]);
    }

    if (mySet.size() <= 1) {
        return true;
    } else {
        return false;
    }
} 

int main() {
    string str = "Race CAd";

    cout << CheckPermutation(str);
}