/*
215. Kth Largest Element in an Array

https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> heap;

        for(int i = 0; i < n; i++){
            heap.push(nums[i]);

            while(heap.size() > k){
                heap.pop();
            }
        }   

        return heap.top();
    }
};
