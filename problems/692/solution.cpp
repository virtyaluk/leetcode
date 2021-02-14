class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans(k);
        unordered_map<string, int> m;
        function<bool(pair<int, string>, pair<int, string>)> cmp = [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
            if (lhs.first == rhs.first) {
                return lhs.second < rhs.second;
            }
            
            return lhs.first > rhs.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> q(cmp);
        
        for (const string& s: words) {
            m[s]++;
        }
        
        for (auto [s, freq]: m) {
            q.push({freq, s});
            
            if (q.size() > k) {
                q.pop();
            }
        }
        
        while (not q.empty()) {
            ans[--k] = q.top().second;
            q.pop();
        }
        
        return ans;
    }
};