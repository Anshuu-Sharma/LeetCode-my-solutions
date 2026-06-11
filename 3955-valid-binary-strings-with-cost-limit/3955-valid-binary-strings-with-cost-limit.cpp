#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int idx, int currentCost, string& path, int n, int k, vector<string>& result) {
        if (idx == n) {
            result.push_back(path);
            return;
        }

        path.push_back('0');
        backtrack(idx + 1, currentCost, path, n, k, result);
        path.pop_back();

        if ((path.empty() || path.back() != '1') && currentCost + idx <= k) {
            path.push_back('1');
            backtrack(idx + 1, currentCost + idx, path, n, k, result);
            path.pop_back();
        }
    }

public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> result;
        string path;
        
        path.reserve(n);
        backtrack(0, 0, path, n, k, result);
        
        return result;
    }
};