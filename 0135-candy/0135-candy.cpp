class Solution {
public:
    int candy(vector<int>& ratings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = ratings.size();
        int left[n], right[n];
        left[0] = 1;
        right[n-1] = 1;

        for(int i = 1; i<=n-1; i++) {
            if(ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
            else left[i] = 1;
        }
        for(int i = n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                right[i] = right[i+1] + 1;
            }
            else right[i]  = 1;
        }

        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum = sum + max(left[i], right[i]);
        }
        return sum;
    }
};