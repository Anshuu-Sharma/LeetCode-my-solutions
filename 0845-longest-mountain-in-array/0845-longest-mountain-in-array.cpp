class Solution {
public:
    // We split into two helpers to ensure we only move in ONE direction
    int getLeftSlope(int idx, vector<int>& arr) {
        if (idx > 0 && arr[idx-1] < arr[idx]) {
            return 1 + getLeftSlope(idx - 1, arr);
        }
        return 0;
    }

    int getRightSlope(int idx, vector<int>& arr) {
        if (idx < arr.size() - 1 && arr[idx+1] < arr[idx]) {
            return 1 + getRightSlope(idx + 1, arr);
        }
        return 0;
    }

    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int longestArr = 0;

        for (int i = 1; i < n - 1; i++) {
            // A mountain MUST have both a left and right slope
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                int left = getLeftSlope(i, arr);
                int right = getRightSlope(i, arr);
                
                // Length = left slope + right slope + 1 (the peak itself)
                longestArr = max(longestArr, left + right + 1);
            }
        }

        return longestArr;
    }
};