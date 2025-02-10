class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = 0,
            maxPop = 0,
            curPop = 0;
        map<int, int> m;
        
        for (const vector<int>& l: logs) {
            m[l.front()]++;
            m[l.back()]--;
        }
        
        for (auto [year, pop]: m) {
            curPop += pop;
            
            if (curPop > maxPop) {
                maxPop = curPop;
                ans = year;
            }
        }
        
        return ans;
    }
};