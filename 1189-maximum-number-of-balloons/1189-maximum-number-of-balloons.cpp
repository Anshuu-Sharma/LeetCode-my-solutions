class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        std::unordered_map<char, int> counts;
        
        for (char c : text) {
            counts[c]++;
        }
        
        return std::min({
            counts['b'],
            counts['a'],
            counts['l'] / 2,
            counts['o'] / 2,
            counts['n']
        });
    }
};