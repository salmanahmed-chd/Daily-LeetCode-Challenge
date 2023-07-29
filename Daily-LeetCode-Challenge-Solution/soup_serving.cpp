808. Soup Servings


https://leetcode.com/problems/soup-servings/description/

class Solution {
public:

    vector<pair<int, int>> serve = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};

    vector<vector<double>> dp;

    double solve(double A, double B){
        if(A <= 0 && B <= 0) return 0.5;
        if(A <= 0) return 1.0;
        if(B <= 0) return 0.0;

        if(dp[A][B] != -1.0) return dp[A][B];

        double prob = 0.0;

        for(auto &opr : serve){
            prob += solve(A-opr.first, B-opr.second);
        }

        return dp[A][B] = 0.25*prob;
    }

    double soupServings(int n) {

        if(n >= 4000) return 1.0;

        dp.resize(n+1, vector<double>(n+1, -1.0));

        return solve(n, n);
        
    }
};
