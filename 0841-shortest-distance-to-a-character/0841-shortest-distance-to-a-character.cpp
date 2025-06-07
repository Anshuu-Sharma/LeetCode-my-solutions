class Solution {
public:
    void helper(int ind, string s, char c, vector<int>& dist) {
        for(int i = ind - 1; i>=0; i--) {
            if(s[i] == c) break;
            else if(dist[i] <= abs(ind-i)) break;
            else dist[i] = abs(ind-i);
        }
        
        for(int i = ind + 1; i<s.size(); i++) {
            if(s[i] == c) break;
            else if(dist[i] <= abs(ind-i)) break;
            else dist[i] = abs(ind-i);
        }
    }
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        stack<int> st;
        
        vector<int> dist(n,INT_MAX);
        for(int i = 0; i<n; i++) {
            if(s[i] == c) {
                st.push(i);
                dist[i] = 0;
            }
        };

        while(!st.empty()) {
            int ind = st.top();
            st.pop();
            helper(ind, s, c, dist);
        }
        return dist;
    }
};