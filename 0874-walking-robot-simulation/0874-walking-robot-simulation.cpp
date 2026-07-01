class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 1. Store obstacles in the hash set using your offset multiplier method
        unordered_set<long long> obs;
        for(auto& it : obstacles){
            long long hashVal = (it[0] + 30000LL) * 100000LL + (it[1] + 30000LL);
            obs.insert(hashVal);
        }

        // 2. Direction arrays: North, East, South, West
        // dx is change in x, dy is change in y
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int dir = 0; // Starts facing North (index 0)
        int x = 0, y = 0;
        int max_dist_sq = 0;

        // 3. Process each command
        for(int cmd : commands) {
            if (cmd == -1) {
                // Turn right: cycle forwards through the direction array
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) {
                // Turn left: cycle backwards (adding 3 is the same as -1 modulo 4)
                dir = (dir + 3) % 4;
            } 
            else {
                // Move forward 'cmd' steps one at a time
                for (int step = 0; step < cmd; ++step) {
                    int next_x = x + dx[dir];
                    int next_y = y + dy[dir];
                    
                    long long next_hash = (next_x + 30000LL) * 100000LL + (next_y + 30000LL);
                    
                    // Check if the next step hits an obstacle
                    if (obs.count(next_hash)) {
                        break; // Stop moving, skip the rest of this command
                    }
                    
                    // Step is clear, update coordinates
                    x = next_x;
                    y = next_y;
                    
                    // Check if this is the furthest we've been
                    max_dist_sq = max(max_dist_sq, x * x + y * y);
                }
            }
        }

        return max_dist_sq;
    }
};