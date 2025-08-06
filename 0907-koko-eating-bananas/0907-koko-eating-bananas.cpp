class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid = low + (high - low) / 2;
            long long totalHours = 0;
            for(auto it: piles){
                totalHours += (it + mid - 1)/mid;
            }
            if(totalHours<=h){
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;
        }   
        return ans;
    }
};