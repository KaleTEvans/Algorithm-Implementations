// Write an algorithm such that if an element in an MxM matrix is 0, it's entire row and column are set to zero

/*
    The first thing that would come to mind would be to simply do a double for loop and upon each 0, set the row and column to 0. However, this would not work,
    because there could potentially be other 0s in the same row or column that go unnoticed when the whole row is set to 0. So, to account for this, we should 
    create another matrix that accounts for all of the 0 locations
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

void nullifyRow(vector<vector<int>> &zeroArr, int row) {
    for (int j=0; j < zeroArr[0].size(); j++) {
        zeroArr[row][j] = 0;
    }
}

void nullifyColumn(vector<vector<int>> &zeroArr, int column) {
    for (int i=0; i < zeroArr.size(); i++) {
        zeroArr[i][column] = 0;
    }
}

void SetZeroes(vector<vector<int>> &zeroArr) {
    // can use arrays to hold 0s for non zero values and 1s for zero
    vector<int> row(zeroArr.size(), 0);
    vector<int> column(zeroArr[0].size(), 0);

    // now loop through the matrix and store values as 1 if the column or row should be a 0
    for (int i=0; i < zeroArr.size(); i++) {
        for (int j=0; zeroArr[i].size(); j++) {
            if (zeroArr[i][j] == 0) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    // nullify rows
    for (int i=0; i < row.size(); i++) {
        if (row[i] == 1) nullifyRow(zeroArr, i);
    }

    // nullify columns
    for (int j=0; j < column.size(); j++) {
        if (column[j] == 1) nullifyColumn(zeroArr, j);
    }
}


int main() {
    vector<vector<int>> zeroArr = {{1, 2, 3, 6, 0, 8, 0},
                                   {3, 0, 4, 1, 2, 0, 1},
                                   {3, 0, 1, 2, 3, 4, 5},
                                   {1, 2, 3, 4, 5, 6, 6}};

    SetZeroes(zeroArr);

    for (int i=0; i < zeroArr.size(); i++) {
        for (int j=0; j < zeroArr[i].size(); j++) {
            cout << zeroArr[i][j] << " ";
        }
        cout << "\n";
    }
}