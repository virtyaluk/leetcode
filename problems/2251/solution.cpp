class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        vector<pair<int, int>> fl;
        map<int, int> line;
        
        for (const vector<int>& f: flowers) {
            fl.push_back({ f.front(), 1 });
            fl.push_back({ f.back() + 1, -1 });
        }
        
        sort(begin(fl), end(fl), [](auto a, auto b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            
            return a.first < b.first;
        });
        
        for (int i = 0, total = 0; i < size(fl); i++) {
            total += fl[i].second;
            line[fl[i].first] = total;
        }
        
        for (const int& p: people) {
            auto it = line.upper_bound(p);
            
            if (it == begin(line)) {
                ans.push_back(0);
            } else {
                ans.push_back(prev(it)->second);
            }
        }
        
        return ans;
    }
};