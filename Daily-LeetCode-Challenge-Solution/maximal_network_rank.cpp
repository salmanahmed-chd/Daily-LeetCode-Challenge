/*
1615. Maximal Network Rank

https://leetcode.com/problems/maximal-network-rank/
*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        int m = roads.size();

        unordered_map<string, int> umap;

        vector<int> indegree(n, 0);

        for(int i = 0; i < m; i++){
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;

            string str = to_string(roads[i][0]) + " " + to_string(roads[i][1]);

            umap[str] = 1;

            str = to_string(roads[i][1]) + " " + to_string(roads[i][0]);

            umap[str] = 1;
        }

        int maxi = -1;

        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                
                string str = to_string(i) + " " + to_string(j);

                if(umap[str] == 1){
                    maxi = max(maxi, indegree[i]+indegree[j]-1);
                }

                else{
                    maxi = max(maxi, indegree[i]+indegree[j]);
                }
            }
            
        }

        return maxi;
    }
};
