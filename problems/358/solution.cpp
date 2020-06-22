class Solution {
public:
    string rearrangeString(string s, int k) {
        string ans;
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        queue<pair<int, char>> q;
        
        for (const char& ch: s) {
            freq[ch]++;
        }
        
        for (auto [ch, cnt]: freq) {
            pq.push({cnt, ch});
        }
        
        while (not empty(pq)) {
            auto [cnt, ch] = pq.top();
            pq.pop();
            
            ans.push_back(ch);
            q.push({cnt - 1, ch});
            
            if (size(q) >= k) {
                if (q.front().first) {
                    pq.push(q.front());
                }
                
                q.pop();
            }
        }
        
        return size(ans) == size(s) ? ans : "";
    }
};