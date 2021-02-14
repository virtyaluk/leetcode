class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<char, vector<pair<int, int>>> um; // pair<wordIdx, charIdx>
        
        for (int i = 0; i < size(words); i++) {
            um[words[i][0]].push_back({i, 0});
        }
        
        for (const char& ch: s) {
            vector<pair<int, int>> bucket = um[ch];
            um[ch] = {};
            
            for (auto [wordIdx, charIdx]: bucket) {
                string word = words[wordIdx];
                charIdx++;
                
                if (charIdx == size(word)) {
                    ans++;
                    continue;
                }
                
                um[word[charIdx]].push_back({wordIdx, charIdx});
            }
        }
        
        return ans;
    }
    
    int numMatchingSubseq1(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<char, vector<int>> um;
        
        for (int i = 0; i < size(s); i++) {
            um[s[i]].push_back(i);
        }
        
        for (const string& word: words) {
            bool countIn = true;
            int prevIdx = 0;
            
            for (const char& ch: word) {
                if (not um.count(ch)) {
                    countIn = false;
                    break;
                }
                
                auto it = lower_bound(begin(um[ch]), end(um[ch]), prevIdx) - begin(um[ch]);
                
                if (it == size(um[ch])) {
                    countIn = false;
                    break;
                }
                
                prevIdx = um[ch][it] + 1;
            }
            
            ans += countIn;
        }
        
        return ans;
    }
};