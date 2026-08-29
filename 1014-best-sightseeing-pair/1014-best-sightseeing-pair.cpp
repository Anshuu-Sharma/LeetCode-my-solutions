class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score = 0;
        int max_i = values[0] + 0; // Tracks the maximum (values[i] + i) seen so far
        
        for (int j = 1; j < values.size(); ++j) {
            // Calculate score with current j: (values[i] + i) + (values[j] - j)
            max_score = max(max_score, max_i + values[j] - j);
            
            // Update max_i for subsequent elements
            max_i = max(max_i, values[j] + j);
        }
        
        return max_score;
    }
};