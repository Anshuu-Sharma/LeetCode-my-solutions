class Solution {
 public:
 //KNK
  long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    long validSubarrays = 0;
    int maxLeft = 0;
    int secondMaxLeft = 0;
    vector<long> gains(n + 1);
    vector<vector<int>> conflicts(n + 1);

    for (const vector<int>& pair : conflictingPairs) {
      const int a = pair[0];
      const int b = pair[1];
      conflicts[max(a, b)].push_back(min(a, b));
    }

    for (int right = 1; right <= n; ++right) {
      for (const int left : conflicts[right]) {
        if (left > maxLeft) {
          secondMaxLeft = maxLeft;
          maxLeft = left;
        } else if (left > secondMaxLeft) {
          secondMaxLeft = left;
        }
      }
      validSubarrays += right - maxLeft;
      gains[maxLeft] += maxLeft - secondMaxLeft;
    }

    return validSubarrays + ranges::max(gains);
  }
};
