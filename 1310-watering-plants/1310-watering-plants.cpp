class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int can = capacity;
        int ans = 0;
        int i = 0;
        int n = plants.size();
        while(i<n){
           
                if(can >= plants[i]){
                    can -= plants[i];
                    i++;
                    ans++;
                }
                else{
                    ans += (i * 2);
                    can = capacity;
                
                }
           
        }
        return ans;
    }
};