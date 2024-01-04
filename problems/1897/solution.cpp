class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = size(words);
        unordered_map<char, int> um;
        
        for (const string& word: words) {
            for (const char& ch: word) {
                um[ch]++;
            }
        }
        
        for (auto [ch, cnt]: um) {
            if (cnt % n != 0) {
                return false;
            }
        }
        
        return true;
    }
};