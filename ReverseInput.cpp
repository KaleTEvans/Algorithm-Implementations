#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string inputString;

int main() {
    cout << "Enter a sentence below" << endl;
    getline(cin, inputString);

    vector<string> sentence;
    string word;

    for (int i=0; i <= inputString.size(); i++) {
        if (inputString[i] == ' ' || i == inputString.size()) {
            sentence.emplace_back(word);
            word.clear();
            continue;
        }

        word.push_back(inputString[i]);
    }

    reverse(sentence.begin(), sentence.end());

    for (int i=0; i < sentence.size(); i++) {
        cout << sentence[i] << " ";
    }
}