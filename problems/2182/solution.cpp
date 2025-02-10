class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        unordered_map<char, int> um;
        priority_queue<pair<char, int>> pq;
        
        for (const char& ch: s) {
            um[ch]++;
        }
        
        for (auto [ch, cnt]: um) {
            pq.push({ch, cnt});
        }
        
        while (not empty(pq)) {
            auto [cha, cnta] = pq.top();
            pq.pop();
            
            if (not empty(ans) and cha == ans.back()) {
                if (not empty(pq)) {
                    auto [chb, cntb] = pq.top();
                    pq.pop();

                    ans += string(1, chb);
                    cntb--;

                    if (cntb > 0) {
                        pq.push({chb, cntb});
                    }
                } else {
                    continue;
                }
            }
            
            ans += string(min(repeatLimit, cnta), cha);
            cnta -= min(repeatLimit, cnta);
            
            if (cnta > 0) {
                pq.push({cha, cnta});
            }
        }
        
        return ans;
    }
};