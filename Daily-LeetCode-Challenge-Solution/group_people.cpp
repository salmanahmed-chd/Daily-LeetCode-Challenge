/*
1282. Group the People Given the Group Size They Belong To

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        vector<vector<int>> ans;

        int n = groupSizes.size();

        unordered_map<int, int> umap;

        for(int i = 0; i < n; i++){
            if(umap.find(groupSizes[i]) == umap.end() || (ans[umap[groupSizes[i]]].size() >= groupSizes[i])){
                vector<int> result;
                ans.push_back(result);

                umap[groupSizes[i]] = ans.size()-1;
            }

            ans[umap[groupSizes[i]]].push_back(i);
        }

        return ans;
    }
};
