class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k), avail(k), ans;
        map<int, int> m;
        int maxCnt;
        
        for (int i = 0, lastIdx = 0; ; i++) {
            if (i < size(arrival)) {
                m[arrival[i]] = load[i];
            } else if (i - lastIdx > k) {
                break;
            }
            
            auto it = m.lower_bound(avail[i % k]);
            // cout << it->first << ": " << it->second << endl;
            
            while (it != end(m)) {
                lastIdx = i;
                cnt[i % k]++;
                avail[i % k] = it->first + it->second;
                m.erase(it);
                it = m.lower_bound(avail[i % k]);
            }
        }
        
        maxCnt = *max_element(begin(cnt), end(cnt));
        
        for (int i = 0; i < k; i++) {
            if (cnt[i] == maxCnt) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};