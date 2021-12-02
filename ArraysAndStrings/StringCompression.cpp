// Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.
// If the compressed string would not become smaller than the original string, your method should return the original string
// You can assume the string has only uppercase and lowercase letters

// The first thing that comes to mind is a hash table. As we loop over the string, we can add each unique letter as a key. As we come across repeated characters, we 
// change the values of the keys to the count of those letters. Once this is complete, we loop over the hash table to insert key-values into a single string
// Then at the end, we would check to make sure the string is shorter than the original

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout;
using std::unordered_map;
using std::string;
using std::vector;

string StrCompression(string &str) {
    vector<char> letterHolder;
    vector<int> numberHolder;
    int count = 1;
    char numberChar;
    string newString;

    for (int i=0; i < str.size(); i++) {
        if (str[i] == str[i+1]) {
            count++;
        } else {
            letterHolder.push_back(str[i]);
            numberHolder.push_back(count);
            count = 1;
        }
    }

    for (int i=0; i < letterHolder.size(); i++) {
        newString.push_back(letterHolder[i]);
        numberChar = '0' + numberHolder[i];
        newString.push_back(numberChar);
    }

    if (newString.size() > str.size()) {
        return str;
    } else {
        return newString;
    }
}

int main() {
    string str = "aabcccccaaa";

    cout << StrCompression(str) << "\n";
}