class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        int n = size(skill),
            total = accumulate(begin(skill), end(skill), 0),
            teamSkill = total / (n / 2);
        unordered_map<int, int> um;
        
        if (teamSkill * (n / 2) != total) {
            return -1;
        }
        
        for (const int& num: skill) {
            if (um.count(teamSkill - num)) {
                ans += num * (teamSkill - num);
                
                if (--um[teamSkill - num] == 0) {
                    um.erase(teamSkill - num);
                }
            } else {
                um[num]++;
            }
        }
        
        if (empty(um)) {
            return ans;
        }
        
        return -1;
    }
};