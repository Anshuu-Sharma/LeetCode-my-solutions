class Solution {
public:
    string frequencySort(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<char, int> freqMap;
    for (char c : s) {
        freqMap[c]++;
    }

    vector<pair<char, int>> freqvec(freqMap.begin(), freqMap.end());

    sort(freqvec.begin(), freqvec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });
    string result;
    for (const auto& pair : freqvec) {
        result.append(pair.second, pair.first);
    }

    return result;
    }
};