class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        long maxi = 0;

        while(i<j){
            int len = min(height[i], height[j]);
            int breadth = j-i;
            maxi = max(maxi, (long)len*breadth);
            if(height[i] < height[j]) i++;
            else j--;
        }

        return maxi;
        
    }
};