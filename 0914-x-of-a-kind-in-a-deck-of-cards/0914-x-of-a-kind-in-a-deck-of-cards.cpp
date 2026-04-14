class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> counts;
        for (int card : deck) {
            counts[card]++;
        }

        int res = 0;
        for (auto const& [card, count] : counts) {
            res = gcd(count, res);
        }

        return res >= 2;
    }
};