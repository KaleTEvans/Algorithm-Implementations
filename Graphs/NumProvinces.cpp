// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Ex. isCOnnected = [[1, 1, 0], [1, 1, 0], [0, 0, 1]] output is 2

// Use a depth first search to solve

#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& isConnected, vector<vector<int>>& vis, int i, int j) {
    if (i < 0 || j < 0 || i >= isConnected.size() || j > isConnected.size()) return;
    vis[i][j] = 1;
    vis[j][i] = 1;
    for (int x=0; i < isConnected.size(); x++) {
        if (!vis[j][x] && isConnected[j][x] == 1) return DFS(isConnected, vis, j, i);
    }
    return;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int province = 0;
    // initialize visited graph for dfs
    vector<vector<int>> vis(isConnected.size(), vector<int>(isConnected.size(), 0));

    for (int i=0; i < isConnected.size(); i++) {
        for (int j=0; j < isConnected[0].size(); j++) {
            if (!vis[i][j] && isConnected[i][j] == 1) {
                DFS(isConnected, vis, i, j);
                province++;
            }
        }
    }
    return province;
}

int main() {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout << findCircleNum(isConnected);
}
