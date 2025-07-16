class Solution {
public:
    pair<int, int> getCoordinates(int x,int n){
        int row = (n-1) - (x-1)/n;
        int col = (x-1)%n;
        if(n%2 == 0 && row%2 == 0 || n%2 != 0 && row%2 != 0){
            col = n-1 - col;
        }
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> vis(n, vector<int>(n, false));
        vis[n-1][0] =true;
        queue<int> q;
        q.push(1);
        int steps = 0;
        while(!q.empty()) {
            int siz = q.size();

           while(siz--){
             int num = q.front();
            q.pop();
            
            if(num == n*n) return steps;

            for(int i = 1; i<=6; i++) {
                if(num + i > n*n) break;
                    pair<int, int> cord = getCoordinates(num+i, n);
                 int nr = cord.first;
                    int nc = cord.second;

                if(vis[nr][nc] == true) continue;
                vis[nr][nc] = true;
                if(board[nr][nc] != -1) q.push(board[nr][nc]);
                else{
                    q.push(num + i);
                } 
            }
           }
           steps++;
        }
        return -1;
    }
};