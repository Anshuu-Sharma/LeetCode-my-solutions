class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        long long length, breadth;
        long long maxi = 0;
        while(i<j){
            length = min(height[i], height[j]);
            breadth = j - i;
            maxi = max(maxi, (length*breadth));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxi;
    }
};