/*
338. Counting Bits

https://leetcode.com/problems/counting-bits/
*/

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> ans(n+1, 0);

        int x;

        for(int i = 1; i <= n; i++){
            x = i&1;

            ans[i] = x + ans[i/2];

        }
        
        return ans;
    }
};
