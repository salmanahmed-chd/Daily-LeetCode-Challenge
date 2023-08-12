/*
63. Unique Paths II

https://leetcode.com/problems/unique-paths-ii/description/
*/

class Solution {
public:

    vector<vector<int>> dp;

    int solve(vector<vector<int>>& grid, int m, int n){
        if(n == 0 && m == 0) return 1;

        if(n < 0 || m < 0 || grid[m][n] == 1) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int up = solve(grid, m-1, n);
        int left = solve(grid, m, n-1);

        return dp[m][n] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        dp.resize(m+1, vector<int>(n+1, -1));

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        return solve(obstacleGrid, m-1, n-1);
        
    }
};
