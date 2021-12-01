// There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character
// Given two strings, write a function to check if they are one edit (or 0 edits) away

/*
    EXAMPLE
    pale, ple -> true
    pales, pale -> true
    pale, bale -> true
    pale, bake -> false
*/  

// Due to the three methods for editing, we can break this problem down to have separate checks for each of the methods
// replacing a character would mean that all letters are identical except for one, so this should be an easy check
// inserting or removing a character would mean that only one character is missing from the string, so these can both be checked together

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::string;

// for simplicity, I will separate the checks into different functions
bool CheckReplace(string &str1, string &str2) {
    // variable to hold amount of differing chars
    int isDiff = 0;

    for (int i=0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            isDiff++;
        }
    }

    if (isDiff > 1) {
        return false;
    } else {
        return true;
    }
}

bool CheckDifference(string &str1, string &str2) {
    // here we can sort the strings and compare them
    // also inserting str1 as the longer string
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    // second string counter variable
    int counter = 0;

    for (int i=0; i < str1.size(); i++) {
        if (str1[i] != str2[counter]) {
            continue;
        }

        counter++;
    }

    if (counter < str2.size()) {
        return false;
    } else {
        return true;
    }
}

bool OneAway(string &str1, string &str2) {

    // declare strings here to ensure the larger one is read first
    string firstString;
    string secondString;
    int letterCount = 1;

    if (str1.size() >= str2.size()) {
        firstString = str1;
        secondString = str2;
    } else {
        firstString = str2;
        secondString = str1;
    }

    // If the strings are more than one char apart, then we can easily assume false
    if (firstString.size() - secondString.size() > 1) return false;

    // now run both checking functions, if at least one is true, return true
    bool a = CheckReplace(firstString, secondString);
    bool b = CheckDifference(firstString, secondString);

    if (a == true || b == true) {
        return true; 
    } else {
        return false;
    }
}

int main() {
    string str1 = "pale";
    string str2 = "pals";

    cout << OneAway(str1, str2);
}