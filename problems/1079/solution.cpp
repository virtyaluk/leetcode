class Solution {
private:
    void backtrack(unordered_map<char, int>& freq, unordered_set<string>& seen, string& candidate) {
        if (not empty(candidate)) {
            seen.insert(candidate);
        }
        
        for (auto [ch, cnt]: freq) {
            if (not cnt) {
                continue;
            }
            
            candidate.push_back(ch);
            freq[ch]--;
            
            backtrack(freq, seen, candidate);
            
            candidate.pop_back();
            freq[ch]++;
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int ans = 0;
        unordered_map<char, int> freq;
        unordered_set<string> seen;
        string candidate;
        
        for (const char& ch: tiles) {
            freq[ch]++;
        }
        
        backtrack(freq, seen, candidate);
        
        return size(seen);
    }
};