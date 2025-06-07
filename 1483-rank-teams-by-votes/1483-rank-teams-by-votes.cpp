struct Team {
    char name;
    vector<int> rank;
    Team(char name, int teamSize) : name(name), rank(teamSize) {}
};

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return "";
        
        string firstVote = votes[0];
        int teamSize = firstVote.size();
        
        // Map team name to its index in the teams vector
        unordered_map<char, int> teamIndex;
        vector<Team> teams;
        for (int i = 0; i < teamSize; ++i) {
            char c = firstVote[i];
            teamIndex[c] = i;  // Map 'A' → 0, 'B' → 1, etc.
            teams.emplace_back(c, teamSize);
        }
        
        // Count votes using the correct index
        for (const string& vote : votes) {
            for (int i = 0; i < teamSize; ++i) {
                char c = vote[i];
                ++teams[teamIndex[c]].rank[i];
            }
        }
        
        // Sort teams by rank and name
        sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
            if (a.rank == b.rank) return a.name < b.name;
            return a.rank > b.rank;
        });
        
        // Build the result
        string ans;
        for (const Team& team : teams)
            ans += team.name;
        return ans;
    }
};
