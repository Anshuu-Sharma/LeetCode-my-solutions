class Solution {
public:
        vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<long long> p;
        long long s = 0;
        for (int a : tasks) {
            s += a;
            p.push_back(s);
        }
        long long d = 0;
        vector<int> res;
        int n = tasks.size();
        for (int t : shifts) {
            if (d + t >= s) {
                res.push_back(0);
                d = 0;
            } else {
                d += t;
                auto it = upper_bound(p.begin(), p.end(), d);
                res.push_back(n - distance(p.begin(), it));
            }
        }
        return res;
    }
};