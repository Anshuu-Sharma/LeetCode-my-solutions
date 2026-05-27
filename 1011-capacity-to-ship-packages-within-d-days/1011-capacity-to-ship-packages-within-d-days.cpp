class Solution {
public:
    bool possible(vector<int>& weights, int days, int cap){
        int load = 0;
        int o_days = 1;
        for(auto it:weights){
            if(load + it > cap){
                o_days++;
                load = it;
            }
            else load += it;
        }
        if(o_days <= days)  return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(weights, days, mid) == true){
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};