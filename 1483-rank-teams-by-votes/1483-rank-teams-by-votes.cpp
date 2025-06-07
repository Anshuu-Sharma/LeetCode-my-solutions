class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> ranks(26, vector<int>(27,0));
        int n = votes[0].size();
        if(n==1) return votes[0];
        // mxn -> here n = 27 because the last column would be used to compare when all columns before 27 would be equal, and that column contains the ASCII values of the char, so the smaller one comes first
        for(auto it:votes[0]) {
            ranks[it - 'A'][26] = it;
        }

        for(auto it:votes) {
            for(int i = 0; i<n; i++) {
                ranks[it[i] - 'A'][i]--;
            }
        }

        sort(ranks.begin(), ranks.end());

        // n is also helpful in returning the string!!!!!!
        string ans = "";
        for(int i = 0; i<n; i++){
            ans += ranks[i][26];
        }
        return ans;

    }
};  