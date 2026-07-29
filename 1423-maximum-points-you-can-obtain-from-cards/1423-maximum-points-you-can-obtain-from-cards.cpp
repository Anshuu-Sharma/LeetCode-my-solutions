class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0;
        int n = cardPoints.size();
        for(int i = 0; i<k; i++) {
            lsum += cardPoints[i];
        }
        int maxSum = lsum;

        int right = n-1;
        for(int i = k-1; i>=0; i--){
            rsum += cardPoints[right];
            lsum -= cardPoints[i];
            right--;
            int sum = rsum + lsum;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};