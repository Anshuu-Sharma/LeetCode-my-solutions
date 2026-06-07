class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }
        
        queue<int> q;
        unordered_set<int> visitedStops;
        vector<bool> visitedBuses(routes.size(), false);
        
        q.push(source);
        visitedStops.insert(source);
        int buses = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                
                if (curr == target) return buses;
                
                for (int bus : stopToBuses[curr]) {
                    if (visitedBuses[bus]) continue;
                    visitedBuses[bus] = true;
                    
                    for (int nextStop : routes[bus]) {
                        if (visitedStops.find(nextStop) == visitedStops.end()) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
            buses++;
        }
        
        return -1;
    }
};