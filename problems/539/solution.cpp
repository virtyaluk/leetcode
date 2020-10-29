class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int ans = INT_MAX;
        
        for (const string& t: timePoints) {
            string h, m;
            
            h.push_back(t[0]);
            h.push_back(t[1]);
            m.push_back(t[3]);
            m.push_back(t[4]);
            
            minutes.push_back(stoi(h) * 60 + stoi(m));
        }
        
        sort(begin(minutes), end(minutes));
        
        for (int i = 1; i < size(minutes); i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }
        
        ans = min(ans, 1440 - minutes.back() + minutes.front());
        
        return ans;
    }
};