class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end()); 
        while (lo < hi) {
            int mid = lo + (hi - lo)/2, cnt = 0; 
            for (auto& qty : quantities) cnt += ceil((double) qty / mid); 
            if (cnt <= n) hi = mid; 
            else lo = mid + 1; 
        }
        return lo; 
    }
};