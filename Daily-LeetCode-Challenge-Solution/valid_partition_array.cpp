/*
2369. Check if There is a Valid Partition For The Array

https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/
*/

class Solution {
public:

    int n;

    vector<int> dp;

    bool solve(vector<int>& nums, int ind){
        if(ind >= n) return true;

        if(dp[ind] != -1) return dp[ind];

        // condition 1

        if(ind+1 < n){
            if(nums[ind] == nums[ind+1]){
                if(solve(nums, ind+2)) return dp[ind] = true;
            }
        }

        if(ind+2 < n){
            // condition 2

            if(nums[ind] == nums[ind+1] && nums[ind] == nums[ind+2]){
                if(solve(nums, ind+3)) return dp[ind] = true;
            }

            // condition 3

            if(nums[ind+1]-nums[ind] == 1 && nums[ind+2]-nums[ind+1] == 1){
                if(solve(nums, ind+3)) return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();

        dp.resize(n+3, -1);

        return solve(nums, 0);
    }
};
