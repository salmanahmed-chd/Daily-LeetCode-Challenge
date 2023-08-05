/*
95. Unique Binary Search Trees II

https://leetcode.com/problems/unique-binary-search-trees-ii/description/
*/

class Solution {
public:

    map<pair<int, int>, vector<TreeNode*>> mp;

    vector<TreeNode*> solve(int start, int end){
        if(start > end) return {NULL};

        if(start == end){
            TreeNode *root = new TreeNode(start);

            return mp[{start, end}] = {root};
        }

        if(mp.find({start, end}) != mp.end()) return mp[{start, end}];

        vector<TreeNode*> result;

        for(int i = start; i <= end; i++){
            vector<TreeNode*> left_bst = solve(start, i-1);
            vector<TreeNode*> right_bst = solve(i+1, end);

            for(TreeNode* leftRoot : left_bst){
                for(TreeNode* rightRoot : right_bst){
                    TreeNode *root = new TreeNode(i);

                    root -> left = leftRoot;
                    root -> right = rightRoot;

                    result.push_back(root);
                }
            }
        }

        return mp[{start, end}] = result;
    }

    vector<TreeNode*> generateTrees(int n) {

        return solve(1, n);
        
    }
};
