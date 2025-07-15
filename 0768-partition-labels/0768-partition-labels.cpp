class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;

        unordered_map<char, int> mpp;
        for(int i = 0; i<s.size(); i++){
            mpp[s[i]] = i;
        }


        int i = 0;
        int end = 0;
        while(i<n) {
            end = mpp[s[i]];
            for(int j = i+1; j<=end; j++){
                end = max(end, mpp[s[j]]);
            }
            int len = end - i+1;
            ans.push_back(len);
            i = end+1;
        }

        return ans;
    }
};