/*
81. Search in Rotated Sorted Array II

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
*/

class Solution {
public:

    bool binarySearch(vector<int>& nums, int l, int r, int target){
        int mid;

        while(l <= r){
            mid = l+(r-l)/2;

            if(nums[mid] == target) return true;

            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int l = 0, r = n-1;

        while(l < n && nums[l] == nums[r]){
            l++;
        }

        if(l > r) return binarySearch(nums, 0, n-1, target);

        int ind = -1;

        int mid;

        while(l <= r){
            mid = l + (r-l)/2;

            if(nums[mid] <= nums[n-1]){
                ind = mid;

                r = mid-1;
            }

            else l = mid+1;
        }

        if(binarySearch(nums, 0, ind-1, target)) return true;

        return binarySearch(nums, ind, n-1, target);
        
    }
};
