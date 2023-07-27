2141. Maximum Running Time of N Computers

https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

class Solution {
public:

    bool possible(vector<int>& batteries, int n, long long mid){
        
        long long minutes = n*mid;

        for(int mint : batteries){
            minutes -= min(mid, (long long)mint);

            if(minutes <= 0) return true;
        }

        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

        long long sum = 0;

        long long l = INT_MAX, r;

        for(int i = 0; i < batteries.size(); i++){
            sum += batteries[i];

            l = min(l, (long long)batteries[i]);
        }

        r = sum/n;

        long long mid = 0;

        long long result = 0;

        while(l <= r){
            mid = l + (r-l)/2;

            if(possible(batteries, n, mid)){
                result = max(mid, result);
                l = mid+1;
            }

            else{
                r = mid-1;
            }
        }
        
        return result;
    }
};
