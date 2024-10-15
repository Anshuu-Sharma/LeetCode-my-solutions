class Solution {
public:
    long long mergeAndCount(vector<char>& s, int left, int mid, int right) {
        vector<char> leftArr(s.begin() + left, s.begin() + mid + 1);
        vector<char> rightArr(s.begin() + mid + 1, s.begin() + right + 1);

        int i = 0, j = 0, k = left;
        long long swaps = 0;

        // Merge the two halves and count the inversions
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                s[k++] = leftArr[i++];
            } else {
                s[k++] = rightArr[j++];
                swaps += (leftArr.size() - i);  // All elements in leftArr[i...] are greater than rightArr[j]
            }
        }

        // Copy remaining elements of leftArr (if any)
        while (i < leftArr.size()) {
            s[k++] = leftArr[i++];
        }

        // Copy remaining elements of rightArr (if any)
        while (j < rightArr.size()) {
            s[k++] = rightArr[j++];
        }

        return swaps;
    }

    long long mergeSortAndCount(vector<char>& s, int left, int right) {
        long long count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in the left half
            count += mergeSortAndCount(s, left, mid);

            // Count inversions in the right half
            count += mergeSortAndCount(s, mid + 1, right);

            // Count split inversions while merging
            count += mergeAndCount(s, left, mid, right);
        }
        return count;
    }

    long long minimumSteps(string s) {
        vector<char> sVector(s.begin(), s.end());
        return mergeSortAndCount(sVector, 0, sVector.size() - 1);
    }
};
