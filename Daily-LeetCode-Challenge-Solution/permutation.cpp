/*

46. Permutations
https://leetcode.com/problems/permutations/description/

*/

class Solution {
public:

    int n;

    void solve(int ind, vector<int>& nums, vector<vector<int>>& result, vector<int>& ans) {

        if (ind == n) {
            result.push_back(ans);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == -11) {
                ans[i] = nums[ind];

                solve(ind + 1, nums, result, ans);

                ans[i] = -11;
            }
        }

        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {

        n = nums.size();

        vector<vector<int>> result;
        vector<int> ans(n, -11);

        solve(0, nums, result, ans);

        return result;
    }
};
