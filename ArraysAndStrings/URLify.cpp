// Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that
// you are given the true length of the string

/*
    EXAMPLE:
    input: 'Mr John Smith    ', 13
    output: 'Mr%20John%20Smith'
*/

// The approach here would be to work backwards, counting the empty spaces and moving the words down the appropriate amount

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::string;

void URLify(string &s, int n) {
    // space and letter counters
    int spaces = 0;
    int letters = 0;

    for (int i=n-1; i >= 0; i--) {
        
    }
}

int main() {
    string s = "Mr John Smith    ";
    int n = 13;

    URLify(s, n);
}