class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mpp;

        while(n){
            int x = n%10;
            mpp[x]++;
            n = n/10;
        }

        int score = 0;
        for(auto it:mpp){
            score += it.first * it.second;
        }
        return score;
    }
};