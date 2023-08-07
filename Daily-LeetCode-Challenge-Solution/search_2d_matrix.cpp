/*
Search a 2D Matrix

https://leetcode.com/problems/search-a-2d-matrix/description/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int size = n*m;

        int l = 0, r = size-1;

        int mid = l + (r-l)/2;

        while(l <= r){
            mid = l + (r-l)/2;

            if(matrix[mid/m][mid%m] == target) return true;

            else if(matrix[mid/m][mid%m] > target) r = mid-1;

            else l = mid+1;
            
        }

        return false;
         
    }
};
