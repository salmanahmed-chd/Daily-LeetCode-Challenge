/*
239. Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result;
        deque<int> que;

        for(int i = 0; i < n; i++){
            while(!que.empty() && que.front() <= i-k){
                que.pop_front();
            }

            while(!que.empty() && nums[que.back()] < nums[i]){
                que.pop_back();
            }

            que.push_back(i);

            if(i >= k - 1){
                result.push_back(nums[que.front()]);
            }
        }

        return result;
    }
};
