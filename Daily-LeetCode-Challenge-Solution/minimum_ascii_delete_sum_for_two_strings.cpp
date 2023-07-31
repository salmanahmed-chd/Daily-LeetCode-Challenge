/*
712. Minimum ASCII Delete Sum for Two Strings
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
*/

class Solution {
public:

    vector<vector<int>> dp;

    int solve(string& s1, string& s2, int n, int m){
        if(n < 0 || m < 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(s1[n] == s2[m]){
            
            int value = 2*s1[n];

            return value + solve(s1, s2, n-1, m-1);
        }

        return dp[n][m] = max(solve(s1, s2, n-1, m), solve(s1, s2, n, m-1));

    }

    int minimumDeleteSum(string s1, string s2) {

        int asciiSum = 0;

        for(char c: s1){
            asciiSum += c;
        }

        for(char c: s2){
            asciiSum += c;
        }

        dp.resize(s1.size(), vector<int> (s2.size(), -1));

        return asciiSum - solve(s1, s2, s1.size()-1, s2.size()-1);
        
    }
};
