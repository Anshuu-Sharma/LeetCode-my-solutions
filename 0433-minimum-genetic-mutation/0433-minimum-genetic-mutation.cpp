class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Load bank into an unordered_set for O(1) lookups
        unordered_set<string> bankSet(bank.begin(), bank.end());
        
        // If the target isn't even in the bank, it's impossible
        if (bankSet.find(endGene) == bankSet.end()) return -1;

        queue<string> q;
        q.push(startGene);
        int steps = 0;
        
        // The only valid characters to mutate to
        vector<char> choices = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            int size = q.size();
            
            // Process all nodes at the current depth level
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();

                // If we reached the target, return the current step count
                if (curr == endGene) return steps;

                // Try mutating each character one by one
                for (int j = 0; j < 8; j++) {
                    char orig = curr[j];
                    
                    for (char c : choices) {
                        if (c == orig) continue; // Skip identical characters
                        
                        curr[j] = c;
                        
                        // If the mutation is valid and in the bank
                        if (bankSet.find(curr) != bankSet.end()) {
                            q.push(curr);
                            // Erase from set to mark as visited and prevent cycles
                            bankSet.erase(curr); 
                        }
                    }
                    // Backtrack the character change for the next iteration
                    curr[j] = orig; 
                }
            }
            // Increment steps after finishing a level
            steps++;
        }
        
        // If the queue empties without finding the endGene, no path exists
        return -1;
    }
};