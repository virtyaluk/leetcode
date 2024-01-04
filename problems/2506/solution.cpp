class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (const string& word: words) {
            int bs = 0;
            
            for (const char& ch: word) {
                bs |= 1 << (ch - 'a');
            }
            
            ans += um[bs]++;
        }
        
        return ans;
    }
};