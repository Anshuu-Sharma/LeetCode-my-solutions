class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans;

        int n = image.size();
        for(int i = 0; i<n; i++) {
            vector<int> temp;
            for(int j = n-1; j>=0; j--) {
                temp.push_back(image[i][j] ^ 1);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};