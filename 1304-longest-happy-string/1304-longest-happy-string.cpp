
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max heap to keep track of available characters
        priority_queue<pair<int, char>> pq;
        
        // Push available characters with their counts into the max heap
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
            // Get the character with the largest remaining count
            auto first = pq.top();
            pq.pop();
            
            // If the last two characters in the result are the same as the current one, we need to pick another character
            if (result.size() >= 2 && result.back() == first.second && result[result.size() - 2] == first.second) {
                if (pq.empty()) break;  // No more characters to use, so we stop
                
                auto second = pq.top();
                pq.pop();
                
                // Add the second most frequent character
                result += second.second;
                if (--second.first > 0) {
                    pq.push(second);  // Reinsert if still available
                }
                
                // Push the first character back into the heap
                pq.push(first);
            } else {
                // Add the most frequent character
                result += first.second;
                if (--first.first > 0) {
                    pq.push(first);  // Reinsert if still available
                }
            }
        }
        
        return result;
    }
};

