class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        visited[0] = 1;

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int temp = q.front();q.pop();
            for(int i = 0; i<rooms[temp].size(); i++){
                int item = rooms[temp][i];
                if(!visited[item]) {
                    visited[item] = 1;
                    q.push(item);
                }
            }
        }

        for(auto it:visited){
            if(it == 0) return false;
        }
        return true;
    }
};