// Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. 
// It is guaranteed there is at least one word that is not banned, and that the answer is unique.

// Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
// Output: "ball"

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> map;
    string temp = "";
    int max = INT_MIN;
    string ans;

    // must first convert the string to lowercase
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    
    for (int i=0; i <= paragraph.size(); i++) {
        if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
            temp = temp + paragraph[i];
        } else {
            if (temp != "") {
                map[temp]++;
                temp = "";
            }
        }
    }

    for (auto i : map) {
        cout << i.first << " " << i.second << endl;
    }
    
    for (int i=0; i < banned.size(); i++) {
        if (map.find(banned[i]) != map.end()) {
            map.erase(banned[i]);
        }
    }
    
    for (auto i : map) {
        if (max < i.second) {
            max = i.second;
            ans = i.first;
        }
    }
    
    return ans;
}

int main() {
    string paragraph = "a, a, a, a, b,b,b,c, c";
    vector<string> banned = {"a"};

    cout << mostCommonWord(paragraph, banned);
}