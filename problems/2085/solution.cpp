class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans = 0;
        unordered_map<string, pair<int, int>> um;
        
        for (const string& word: words1) {
            um[word].first++;
        }
        
        for (const string& word: words2) {
            um[word].second++;
        }
        
        for (auto [ignore, cnt]: um) {
            ans += cnt.first == 1 and cnt.second == 1;
        }
        
        return ans;
    }
};