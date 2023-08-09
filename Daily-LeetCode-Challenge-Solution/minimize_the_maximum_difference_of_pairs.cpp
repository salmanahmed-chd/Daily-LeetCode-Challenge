/*
2616. Minimize the Maximum Difference of Pairs

https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
*/

class Solution {
public:

    int solve(vector<int>& nums, int mid){
        int n = nums.size();

        int i = 1;

        int ans = 0;

        while(i < n){
            if(abs(nums[i]-nums[i-1]) <= mid){
                ans++;
                i += 2;
            }

            else i++;
        }

        return ans;
    }

    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        if(p == 0) return 0;

        int l = 0, r = nums[n-1]-nums[0];

        int mid;

        int result = r;

        while(l <= r){
            mid = l + (r-l)/2;

            if(solve(nums, mid) >= p){
                result = mid;
                r = mid-1;
            }

            else{
                l = mid+1;
            }
        }

        return result;

    }
};
