class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // slope must be same
        // this slope formula causes division by zero error 
        //int slope = (coordinates[1][1]  - coordinates[0][1]) / (coordinates[1][0]  - coordinates[0][0]);
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];

        for(int i = 2; i < coordinates.size(); i++){
            int xi = coordinates[i][0], yi = coordinates[i][1];
            
            if ((y1 - y0) * (xi - x0) != (yi - y0) * (x1 - x0)) {
                return false;
            }
        }
        return true;

    }
};