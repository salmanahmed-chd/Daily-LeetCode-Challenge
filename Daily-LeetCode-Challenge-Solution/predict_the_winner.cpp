486. Predict the Winner

https://leetcode.com/problems/predict-the-winner/description/

class Solution {
public:

    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int j){
        if(i > j) return 0;
        if(i == j) return nums[i];

        if(dp[i][j] != -1) return dp[i][j];

        int take_i = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
        int take_j = nums[j] + min(solve(nums, i, j-2), solve(nums, i+1, j-1));

        return dp[i][j] = max(take_i, take_j);
    }

    bool PredictTheWinner(vector<int>& nums) {

        dp.resize(21, vector<int>(21, -1));
        
        int totSum = accumulate(nums.begin(), nums.end(), 0);

        int playerOne = solve(nums, 0, nums.size()-1);

        return playerOne >= totSum -playerOne;

    }
};
