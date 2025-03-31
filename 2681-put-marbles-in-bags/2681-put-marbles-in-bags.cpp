class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> arr;

        for(int i = 0; i<n-1; i++){
            arr.push_back(weights[i]+weights[i+1]);
        }
        
        sort(arr.begin(),arr.end());

        long long min_val = 0;
        long long max_val = 0;
        for(int i = 0; i<k-1; i++){
            min_val += arr[i];
            max_val += arr[n-2-i];
        }

        return max_val-min_val;
    }
};