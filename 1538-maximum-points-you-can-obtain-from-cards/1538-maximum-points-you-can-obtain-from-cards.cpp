class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int lsum = 0 ,rsum = 0, maxsum = 0;
        for (int i = 0; i <k ; i++) {
            lsum += cardPoints[i];
       }
       int right = cardPoints.size() - 1;
       maxsum = lsum;
       for (int i = k - 1; i >= 0; i--) {
        lsum = lsum - cardPoints[i];
        rsum = rsum + cardPoints[right];
        right--;
        maxsum = max(maxsum, lsum+rsum);
       }
       return maxsum;
    }
};