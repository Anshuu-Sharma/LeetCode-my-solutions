class Solution {
public:
    int findLengthOfShortestSubarray(std::vector<int>& arr) {
        //KNK
        int n = arr.size(); 
        int left = 0, right = n - 1; 

        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            ++left;
        }
        if (left == n - 1) {
            return 0;
        }

        while (right > 0 && arr[right - 1] <= arr[right]) {
            --right;
        }


        int minSubarrayLength = std::min(n - left - 1, right);
        for (int l = 0, r = right; l <= left; ++l) {
            while (r < n && arr[r] < arr[l]) {
                ++r;
            }
            minSubarrayLength = std::min(minSubarrayLength, r - l - 1);
        }

        return minSubarrayLength;
    }
};