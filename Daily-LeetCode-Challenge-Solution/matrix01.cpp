/*
542. 01 Matrix

https://leetcode.com/problems/01-matrix/description/
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        auto isSafe = [&](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n;
        };
        
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            
            for (auto& dir : directions) {
                int i = x + dir.first;
                int j = y + dir.second;
                
                if (isSafe(i, j) && dist[i][j] == -1) {
                    que.push({i, j});
                    dist[i][j] = 1 + dist[x][y];
                }
            }
        }
        
        return dist;
    }
};
