class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int alice = n-1;
        int bob = 0;
        int me = alice - 1;
        int sum = 0;
        while(bob<me && me<alice)
        {
            sum+=piles[me];
            alice-=2;
            bob++;
            me=alice-1;
        }
        return sum;
    }
};