class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int, int> m;
        int ans = 0;
        
        for (int day = 0; day < days.size() || m.upper_bound(day) != m.end(); day++) {
            if (day < days.size()) {
                m[day + days[day]] += apples[day];
            }
            
            auto it = m.upper_bound(day);
            
            if (it != m.end()) {
                ans++;
                
                if (it->second > 1) {
                    m[it->first]--;
                } else {
                    m.erase(it);
                }
            }
        }
        
        return ans;
    }
};