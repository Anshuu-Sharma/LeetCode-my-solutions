class Solution {
public:
    int minSetSize(vector<int>& arr) {
        /*
        return the number of unique integers to be removed which results the size of array to be n/2

        make a freq hash

        freq hash: (n = 10) target n = 5
        2: 2
        3: 4
        5: 3
        7: 1

        so now we need to find the combination of elements that sum upto target n
        */
        vector<int> freq(1e5 + 1, 0);
        for (int i = 0; i < arr.size(); i++)
            freq[arr[i]]++;

        priority_queue<int> pq;
        for (int i = 1; i < 1e5 + 1; i++)
            pq.push(freq[i]);

        int minSetSize = 0;
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            minSetSize++;
            if (sum >= arr.size() / 2)
                break;
            pq.pop();
        }
        return minSetSize;
    }
};