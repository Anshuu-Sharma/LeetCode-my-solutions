class Solution {
public:
    bool isDiffPossible(vector<int>& price, int mid, int k) {
        int prevPrice = price[0];
        int baskets = 1;

        for(int i = 1; i<price.size(); i++){
            if(price[i] - prevPrice >= mid) {
                baskets++;
                prevPrice = price[i];
            }
            if(baskets>=k) return true;
        }

        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        ranges::sort(price);

      int ans = 0;
      int l = 0; 
      int r = ranges::max(price) - ranges::min(price) + 1;

        while(l<r) {
            int mid = l + (r - l)/2;

            if(isDiffPossible(price, mid, k)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid;
        }

        return ans;
    }
};