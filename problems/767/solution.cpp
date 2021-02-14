class Solution {
public:
    string reorganizeString(string s) {
        int n = size(s), idx = 0;
        string ans(n, ' ');
        unordered_map<char, int> um;
        priority_queue<pair<int, char>> pq;
        
        for (const char& ch: s) {
            um[ch]++;
        }
        
        for (auto &[ch, cnt]: um) {
            pq.push({cnt, ch});
        }
        
        while (not empty(pq)) {
            auto [cnt, ch] = pq.top();
            pq.pop();
            
            if (cnt > (n + 1) / 2) {
                return "";
            }
            
            while (cnt) {
                idx = idx >= n ? 1 : idx;
                
                cnt--;
                ans[idx] = ch;
                idx += 2;
            }
        }
        
        return ans;
    }
};