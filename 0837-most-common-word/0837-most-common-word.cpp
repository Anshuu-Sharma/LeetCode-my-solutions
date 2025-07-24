class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mpp;
        string ans = "";
        int maxi = 0;

        for(auto it:banned) {
            mpp[it] = -1;
        }

        int i = 0;
        int n = paragraph.size();
        while(i<n) {
            string temp = "";
            // char c = (i < n) ? paragraph[i] : ' '; // Add space at end to handle last word

            while(i<n && !isalpha(paragraph[i])) {
                i++;
                continue;
            }
            while (isalpha(paragraph[i])) {
                temp += tolower(paragraph[i]);
                i++;
            }

            if(mpp[temp] == -1) continue;

            else {
                mpp[temp]++;
                if(maxi < mpp[temp]){
                    maxi = mpp[temp];
                    ans = temp;
                }
            }
        }

        return ans;


        
    }
};