class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> arr;
        arr.reserve(m * n);

        int row = 0, col = 0;
        bool up = true;                    

        while (arr.size() < m * n) {
            arr.push_back(mat[row][col]);

            if (up) {                      
                if (col == n - 1) {        // hit right border → go down
                    ++row;
                    up = false;
                } else if (row == 0) {     // hit top border → go right
                    ++col;
                    up = false;
                } else {                   // normal up-right step
                    --row; ++col;
                }
            } else {                       // moving down-left
                if (row == m - 1) {        // hit bottom border → go right
                    ++col;
                    up = true;
                } else if (col == 0) {     // hit left border → go down
                    ++row;
                    up = true;
                } else {                   // normal down-left step
                    ++row; --col;
                }
            }
        }
        return arr;
    }
};
