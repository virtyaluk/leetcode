class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        string ans, cur;
        int maxSoFar = 0;
        unordered_map<string, int> freq;
        unordered_set<string> b{begin(banned), end(banned)};
        
        for (int i = 0; i < size(p); i++) {
            if (isalpha(p[i])) {
                cur.push_back(tolower(p[i]));
            }
            
            if (not isalpha(p[i]) or i == size(p) - 1) {
                if (empty(cur)) {
                    continue;
                }
                
                if (not b.count(cur)) {
                    freq[cur]++;
                    
                    if (maxSoFar < freq[cur]) {
                        ans = cur;
                        maxSoFar = freq[cur];
                    }
                }
                
                cur.clear();
            }
        }
        
        return ans;
    }
};