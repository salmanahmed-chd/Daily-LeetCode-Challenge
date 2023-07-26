1870. Minimum Speed to Arrive on Time

https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:

    double find(double mid, vector<int>& dist){
        double time = 0;

        for(int j = 0; j < dist.size()-1; j++){
            time += ceil((double) dist[j]/(double) mid);
        }

        time += (double) dist[dist.size()-1]/ (double) mid;

        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int n = dist.size();

        int i = 1;

        int l = 1, r = INT_MAX-1;

        int mid;

        int result = INT_MAX;

        while(l <= r){
            mid = l + (r-l)/2;

            if(find((double) mid, dist) <= hour){
                result = min(result, mid);
                r = mid-1;
            }

            else{
                l = mid+1;
            }
        }



        if(result == INT_MAX){
            return -1;
        }

        return result;
        
    }
};

SC = O(1) and TC = O(N*log(INT_MAX)) ≈ O(N)
