class Solution {
public:
    string customSortString(string order, string str) {
        string ans;
        unordered_map<char, int> freq;
        
        for (const char& ch: str) {
            freq[ch]++;
        }
        
        for (const char& ch: order) {
            if (freq.count(ch)) {
                ans += string(freq[ch], ch);
                freq.erase(ch);
            }
        }
        
        for (auto [ch, n]: freq) {
            ans += string(n, ch);
        }
        
        return ans;
    }
    
    string customSortString1(string order, string str) {
        unordered_map<char, int> abc;
        
        for (int i = 0; i < size(order); i++) {
            abc[order[i]] = i;
        }
        
        sort(begin(str), end(str), [&](const char& lhs, const char& rhs) {
            int lPos = abc.count(lhs) ? abc[lhs] : 27,
                rPos = abc.count(rhs) ? abc[rhs] : 27;
            
            return lPos < rPos;
        });
        
        return str;
    }
};