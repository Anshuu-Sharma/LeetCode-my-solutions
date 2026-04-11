class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs;
        vector<string> digitLogs;

        // 1. Separate the logs i.e. number logs or digit logs
        for (const string& log : logs) {
            int firstSpace = log.find(' '); 
            if (isdigit(log[firstSpace + 1])) {
                digitLogs.push_back(log);
            } else {
                letterLogs.push_back(log);
            }
        }

        // 2. Sort only the letter-logs using a custom comparator
        sort(letterLogs.begin(), letterLogs.end(), [](const string& a, const string& b) {
            int posA = a.find(' ');
            int posB = b.find(' ');

            string contentA = a.substr(posA + 1);
            string contentB = b.substr(posB + 1);

            // Sort by content first
            if (contentA != contentB) return contentA < contentB; // means lexicographically smaller value will come first
            // If content matches, sort by the full log (lexicographical identifier)
            return a < b;
        });

        // 3. Combine them: letter-logs first, then digit-logs
        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
        return letterLogs;
    }
};
