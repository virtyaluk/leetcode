class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        map<int, int> m;
        
        sort(begin(items), end(items));
        
        for (int i = 0, b = 0; i < size(items); i++) {
            b = max(b, items[i].back());
            m[items[i].front()] = max(m[items[i].front()], b);
        }
        
        for (const int& price: queries) {
            auto it = m.upper_bound(price);
            
            if (it != begin(m)) {
                ans.push_back((--it)->second);
            } else {
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};