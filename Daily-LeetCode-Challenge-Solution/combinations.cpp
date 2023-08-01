/*
77. Combinations

https://leetcode.com/problems/combinations/description/
*/

class Solution {
public:

    void solve(int n, int k, vector<vector<int>>& ans, vector<int>& nums){
        if(nums.size() == k){
            ans.push_back(nums);
            return;
        }

        if(n == 0){
            return;
        }

        nums.push_back(n);

        solve(n-1, k, ans, nums);

        nums.pop_back();

        solve(n-1, k, ans, nums);
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;

        vector<int> nums;
        
        if(n == k){

            for(int i = 1; i <= n; i++){
                nums.push_back(i);
            }

            ans.push_back(nums);

            return ans;
        }

        solve(n, k, ans, nums);
        
        return ans;
    }
};
