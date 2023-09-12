/*
1647. Minimum Deletions to Make Character Frequencies Unique

https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/
*/

class Solution {
public:
    int minDeletions(string s) {

        int n = s.size();

        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }

        int result = 0;

        unordered_set<int> st;

        for(int i = 0; i < 26; i++){
            while(st.find(freq[i]) != st.end() && freq[i] > 0){
                freq[i]--;
                result++;
            }

            st.insert(freq[i]);
        }

        return result;
        
    }
};
