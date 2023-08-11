/*
518. Coin Change II

https://leetcode.com/problems/coin-change-ii/description/
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int sum = 0; sum <= amount; sum++){
            dp[0][sum] = (sum%coins[0] == 0);
        }  

        for(int ind = 0; ind < n; ind++){
            dp[ind][0] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 1; sum <= amount; sum++){
                int notTake = dp[ind-1][sum];

                int take = 0;

                if(sum >= coins[ind]) take = dp[ind][sum-coins[ind]];

                dp[ind][sum] = take+notTake;
            }
        }

        return dp[n-1][amount];
    }
};
