class Solution {
public:
    int make_row_palindrome(vector<int> arr, int n){
        int low = 0;
        int high = n-1;
        int cnt = 0;
        while(low<high){
            if(arr[low] != arr[high]) {
                arr[low] = arr[high];
                cnt++;
            }
            low++;
            high--;
            
        }
        return cnt;
    }
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int t1 = 0;
        int t2 = 0;

        for(int i = 0; i<n; i++){
            t1 += make_row_palindrome(grid[i],m);
        }

        for(int i = 0; i<m; i++){
            vector<int> temp;
            for(int j = 0; j<n; j++){
                temp.push_back(grid[j][i]);
            }
            t2 += make_row_palindrome(temp, n);
        }

        if(t1>t2) return t2;
        return t1;

    }
};
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
