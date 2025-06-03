class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMaxArr(n,-1);
        vector<int> rightMaxArr(n,-1);

        leftMaxArr[0] = height[0];
        rightMaxArr[n-1] = height[n-1];
        for(int i = 1; i<n; i++) {
            leftMaxArr[i] = max(height[i], leftMaxArr[i-1]);
            rightMaxArr[n-i-1] = max(height[n-i-1], rightMaxArr[n-i]);
        }
        
        int water = 0;
        for(int i = 1; i<n-1; i++) {
            water += min(leftMaxArr[i], rightMaxArr[i]) - height[i];
        }
        return water;
    }
};