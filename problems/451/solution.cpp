class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> freqs;
        vector<pair<char, int>> freq;
        
        for (const char& ch: s) {
            freqs[ch]++;
        }
        
        for (auto [ch, cnt]: freqs) {
            freq.push_back({ch, cnt});
        }
        
        sort(begin(freq), end(freq), [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            
            return a.second > b.second;
        });
        
        for (auto [ch, cnt]: freq) {
            ans += string(cnt, ch);
        }
        
        return ans;
    }
};