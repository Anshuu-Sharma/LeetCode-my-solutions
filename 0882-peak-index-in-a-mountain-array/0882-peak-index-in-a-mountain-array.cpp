class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int l = 0;
        int h = n-1;
        int ans = 1;
        while(l<=h) {
            int mid = l + (h - l)/2;

            if(mid<n-1 && (arr[mid] >= arr[mid+1])) {
                ans = mid;
                h = mid-1;
            }

            else if(mid<n-1 && (arr[mid] <= arr[mid+1])){
                l = mid+1;
            }
        }

        return ans;
    }
};