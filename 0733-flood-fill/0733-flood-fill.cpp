class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr, int sc, int drow[], int dcol[], int color, int iniColor, vector<vector<int>>& ans){
        ans[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();

        for(int i = 0; i<4; i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && (image[nrow][ncol] == iniColor) && ans[nrow][ncol] != color){
                dfs(image, nrow, ncol, drow, dcol, color, iniColor, ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];

        vector<vector<int>> ans = image;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        dfs(image, sr, sc, drow, dcol, color, iniColor, ans);
        return ans;
    }
};