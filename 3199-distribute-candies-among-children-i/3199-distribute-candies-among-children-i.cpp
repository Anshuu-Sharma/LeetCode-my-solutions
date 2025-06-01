class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt = 0;
        int firstMin = max(0, n - limit - limit);
        int firstMax = min(limit, n);
        for (int x = firstMin; x <= firstMax; ++x) {
            int minY = max(0, n - x - limit);
            int maxY = min(limit, n - x);
            if (minY <= maxY) {
                cnt += (maxY - minY + 1);
            }
        }
        return cnt;
    }
};
