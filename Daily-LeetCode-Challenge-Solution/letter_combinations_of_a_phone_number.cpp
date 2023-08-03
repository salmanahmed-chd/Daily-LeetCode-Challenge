/*
17. Letter Combinations of a Phone Number

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

class Solution {
public:

    int n;

    void solve(string digits, unordered_map<int, string>& umap, vector<string>& result, string& str, int ind){
        if(ind == n){
            result.push_back(str);

            return;
        }


        string s = umap[digits[ind]-'0'];

        for(char c : s){
            str += c;
            solve(digits, umap, result, str, ind+1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        n = digits.size();

        if(n == 0) return {};

        unordered_map<int, string> umap;

        umap[2] = "abc";
        umap[3] = "def";
        umap[4] = "ghi";
        umap[5] = "jkl";
        umap[6] = "mno";
        umap[7] = "pqrs";
        umap[8] = "tuv";
        umap[9] = "wxyz";

        vector<string> result;

        string str = "";

        solve(digits, umap, result, str, 0);

        return result;
        
    }
};
