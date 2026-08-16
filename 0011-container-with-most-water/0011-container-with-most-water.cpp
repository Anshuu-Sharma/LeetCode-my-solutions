class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n - 1;
        int maxi = 0;
        while(l<r){
            maxi = max(maxi, (min(height[l], height[r]) * (r-l)));

            if(height[l] >= height[r]) r--;
            else l++;
        }

        return maxi;
    }
};