class Solution {
public:
    int helper(vector<string>& garbage, char truck, vector<int>& travel){
        int cnt = 0;
        int last_pos = 0;

        for(int i = 0; i<garbage.size(); i++){
           cnt += count(garbage[i].begin(), garbage[i].end(), truck);

           if(garbage[i].find(truck) != string::npos){
            last_pos = i;
           }
        }

        for(int i = 0; i<last_pos; i++){
            cnt += travel[i];
        }

        return cnt;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int minutes = 0;
        minutes += helper(garbage, 'G', travel);
        minutes += helper(garbage, 'M', travel);
        minutes += helper(garbage, 'P', travel);
        return minutes;
    }
};