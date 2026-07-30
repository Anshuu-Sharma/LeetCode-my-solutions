class Solution {
public:
    bool isMidPassed(int mid, vector<int>& position, int m) {
        int pind = position[0];
        int balls = 1;
        for(int i = 1; i<position.size(); i++) {
            if(position[i] - pind >= mid) {
                balls++;
                pind = position[i];
                if(balls==m) return true;
            }
        }

        return (balls>=m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = position.back() - position.front();
        int ans = -1;

        while(low<=high) {
            int mid = low + (high - low)/2;

            if(isMidPassed(mid, position, m)) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};