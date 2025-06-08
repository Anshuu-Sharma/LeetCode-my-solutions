class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> temp;

        for(int i = 1; i<=n; i++) {
            string s = to_string(i);
            temp.push_back(s);
        }

        sort(temp.begin(), temp.end());
        for(int i = 0; i<temp.size(); i++) {
            ans.push_back(stoi(temp[i]));
        }
        return ans;
    }
};