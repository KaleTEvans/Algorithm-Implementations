#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fillRow(vector<vector<int>>& ans, int i, int index) {
    if (i > index) return ans;
    vector<int> temp;
    temp.push_back(1);
    if (i > 0) {
        for (int j=1; j < i; j++) {
            temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
        temp.push_back(1);
    }
    
    ans.push_back(temp);
    return fillRow(ans, ++i, index);
}

vector<int> getRow(int rowIndex) {
    vector<vector<int>> ans;
    vector<int> final;
    int i=0;
    ans = fillRow(ans, i, rowIndex);
    for (int i=0; i <= rowIndex; i++) {
        final.push_back(ans[rowIndex][i]);
    }
    return final;
}

void printArr(vector<vector<int>> arr) {
    for (int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rowIndex = 4;

    vector<int> ans = getRow(rowIndex);

    for (int i=0; i < ans.size(); i++) cout << ans[i] << " ";
}