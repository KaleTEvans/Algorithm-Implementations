// Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

// this is essentially a 90 degree rotation of a 4x4 matrix
/*
    1 2 3 4        1 1 1 1
    1 2 3 4  ->    2 2 2 2
    1 2 3 4        3 3 3 3
    1 2 3 4        4 4 4 4 

    Another way to look at it:
    [i1][j1] [i2][j1] [i3][j1] [i4][j1]         [i1][j4] [i1][j3] [i1][j2] [i1][j1]
    [i1][j2] [i2][j2] [i3][j2] [i4][j2]   ->    [i2][j4] [i2][j3] [i2][j2] [i2][j1]
    [i1][j3] [i2][j3] [i3][j3] [i4][j4]         [i3][j4] [i3][j3] [i3][j2] [i3][j1]
    [i1][j4] [i2][j4] [i3][j4] [i4][j4]         [i4][j4] [i4][j3] [i4][j2] [i4][j1]
*/

// There are multiple ways to rotate a matrix, some being more space consuming and difficult
// One simple yet challenging way to do this would be to inverse all of the columns and then perform a matrix transpose

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;

vector<vector<int>> RotateMatrix(vector<vector<int>> &image) {
    // variable to hold new matrix after transpose
    vector<vector<int>> transpose(4, vector<int>(4, 0));
    // to inverse the columns, we could use the built in reverse function 
    std::reverse(std::begin(image), std::end(image));

    int value;
    // to complete the transpose we will need to use a double for loop
    for (int i=0; i < image.size(); i++) {
        for (int j=0; j < image[i].size(); j++) {
            transpose[j][i] = image[i][j];
        }
    }

    return transpose;
}

void PrintMatrix(vector<vector<int>> &transpose) {
    for (auto n : transpose) {
        for (auto i : n) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> image = {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                 {1, 2, 3, 4},
                                 {5, 6, 7, 8}};
    
    vector<vector<int>> transpose = RotateMatrix(image);
    PrintMatrix(transpose);
}