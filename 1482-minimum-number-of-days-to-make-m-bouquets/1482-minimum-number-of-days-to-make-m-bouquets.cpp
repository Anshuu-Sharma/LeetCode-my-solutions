class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int days){
        long long cnt = 0;
        long long bouq = 0;
        for(auto it:bloomDay){
            if(it <= days){
                cnt++;
            }
            else{
                bouq += floor(double(cnt)/k);
                cnt = 0;
            }
        }
        bouq += floor(double(cnt)/k);
        if(bouq<m) return false;
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long low = *min_element(bloomDay.begin(), bloomDay.end());
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high - low)/2;
            
            if(possible(bloomDay, m, k, mid) == true){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};