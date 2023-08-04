/*
139. Word Break

https://leetcode.com/problems/word-break/description/
*/

class Solution {
public:

    int n;

    vector<int> dp;

    bool solve(string s, unordered_set<string>& dict, int idx){
        if(idx == n) return true;

        if(dict.find(s) != dict.end()) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int l = 1; l <= n; l++){

            string remain = s.substr(idx, l);

            if(dict.find(remain) != dict.end() && solve(s, dict, idx+l)) return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        n = s.size();

        unordered_set<string> dict;

        dp.resize(n+1, -1);

        for(string &str : wordDict){
            dict.insert(str);
        }

        return solve(s, dict, 0);
    }
};
