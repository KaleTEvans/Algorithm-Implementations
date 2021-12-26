// Check if a string is a valid palindrome. Can contain other characters
// Ex. s = "A man, a plan, a canal: Panama"
// Correct answer would be true, as "amanaplanacanalpanama" is a palindrome.

#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(string& s) {

    string k;
        
    for (int i=0; i < s.size(); i++) {
        k.push_back(tolower(s[i]));
    }
    
    string r1;
    string r2;
    
    for (int i=0; i < k.size(); i++) {
        if (int(k[i]) >= 97 && int(k[i]) <= 122) {
            r1.push_back(k[i]);
            r2.push_back(k[i]);
        }
    }

    for (int i=0; i < r1.size(); i++) {
        cout << r1;
    }
    
    reverse(r2.begin(), r2.end());
    
    for (int i=0; i < r1.size(); i++) {
        if (r1[i] != r2[i]) return false;
    }
    
    return true;
    
}

int main() {
    string s = "abcbca";

    cout << isPalindrome(s);
}

