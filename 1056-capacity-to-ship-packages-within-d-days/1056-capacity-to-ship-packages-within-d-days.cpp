class Solution {
public:
    int finddays(vector<int> weights, int mid, int n) {
        int days = 1, load = 0;
        for (int i = 0; i<n; i++) {
            if((load + weights[i]) > mid) {
                days++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        cin.tie(nullptr) -> sync_with_stdio(false);
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low<=high){
            int mid = (low + high) / 2;
            int no_of_days = finddays(weights, mid, n);
            if(no_of_days <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
            return low;
    }
};