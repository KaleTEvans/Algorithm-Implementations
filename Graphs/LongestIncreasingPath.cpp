// Given an m x n integers matrix, return the length of the longest increasing path in matrix.
// This means that starting at any value in the matrix,the longest path only inlcudes values that are greater than the previous

#include <algorithm>
#include <iostream>
// include this library to find the max of more than 2 items
#include <initializer_list>
#include <vector>

using namespace std;

int BFS(vector<vector<int>>& matrix, int i, int j, int prev, int count) {
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) return count;
    int cur = matrix[i][j];
    
    if (cur > prev) {
        count++;
        return max({BFS(matrix, i+1, j, cur, count), BFS(matrix, i, j+1, cur, count),
                    BFS(matrix, i-1, j, cur, count), BFS(matrix, i, j-1, cur, count)});
    } else {
        return count;
    }
}

// a traditional DFS will take a total time of O(2^n) due to needing to loop through the matrix as well as adjacent cells
// one way to speed this up, would be to create a cache matrix, that stores the maximum path value of each cell

// this directional vector will simplify checking adjacent cells
vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache) {
    if (cache[i][j] != 0) return cache[i][j];
    
    for (auto d : dirs) {
        int x = i + d[0];
        int y = j + d[1];

        if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
            cache[i][j] = max(cache[i][j], DFS(matrix, x, y, cache));
        }
    }

    return ++cache[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int count = 0;

    vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), 0));
    
    for (int i=0; i < matrix.size(); i++) {
        for (int j=0; j < matrix[0].size(); j++) {
            count = max(count, DFS(matrix, i, j, cache));
        }
    }
    
    for (int i=0; i < cache.size(); i++) {
        for (int j=0; j < cache[0].size(); j++) {
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }
    
    return count;
}

int main() {
    vector<vector<int>> matrix = {{9,9,4}, {6,6,8}, {2,1,1}};

    cout << longestIncreasingPath(matrix);
}