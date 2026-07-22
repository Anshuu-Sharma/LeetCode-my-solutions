class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
    
       // 'lakes' maps lake number -> the last day it was filled
       unordered_map<int, int> lakes;

       // 'dry' stores indices of days when we can dry any lake (rains[i] == 0)
       // We use a set so we can efficiently find the earliest dry day after a certain index
       set<int> dry;

       int n = rains.size();
       vector<int> ans(n, 1); // Initialize all answers to 1 (for dry days we’ll later assign which lake to dry)

       for (int i = 0 ; i < n; i++) {
        if (rains[i] == 0) {
            // If it's a dry day, remember its index
            // We'll decide later which lake to dry on this day
            if (!lakes.empty())
                dry.insert(i);
            continue;
        }

        // If this lake has never been filled before
        if (lakes.find(rains[i]) == lakes.end()) {
            lakes[rains[i]] = i;
            ans[i] = -1;
            continue;
        }
        
        if (dry.empty() == true) return {}; // No dry day available → flood inevitable

        else {

            // Find the first dry day index that comes *after* the last rain day for this lake
            auto el = dry.lower_bound(lakes[rains[i]] + 1);

        
            if (el == dry.end()) return {};

            // Schedule to dry this lake on that dry day
            ans[*el] = rains[i];
            ans[i] = -1;

            // Update the lake’s last filled day
            lakes[rains[i]] = i;
            dry.erase(el);
        }
       }

       return ans;
    }
};