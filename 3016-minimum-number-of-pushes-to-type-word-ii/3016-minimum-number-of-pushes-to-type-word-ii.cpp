class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: Count the frequency of each letter
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }
        
        // Step 2: Sort frequencies in descending order
        sort(count.rbegin(), count.rend());
        
        int totalPushes = 0;
        
        // Step 3: Calculate the total cost
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) break; // Stop if there are no more characters
            
            // i / 8 groups every 8 characters into the next push tier:
            // Indices 0-7 -> (0 / 8) + 1 = 1 push
            // Indices 8-15 -> (8 / 8) + 1 = 2 pushes
            // Indices 16-23 -> (16 / 8) + 1 = 3 pushes, etc.
            int pushes = (i / 8) + 1;
            
            totalPushes += count[i] * pushes;
        }
        
        return totalPushes;
    }
};