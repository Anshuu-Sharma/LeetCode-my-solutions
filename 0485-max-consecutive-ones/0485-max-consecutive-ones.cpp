class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int cnt = 0;
        int maxcnt = 0;
        for (auto it : nums) {
            if (it == 1) {
                cnt++;
            }

            else if (it == 0) {
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
            }
        }
        maxcnt = max(maxcnt, cnt);
        return maxcnt;
        }
};