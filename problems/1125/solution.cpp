class Solution {
private:
    unordered_set<int> ansTeam;
    int teamSize;
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, unordered_set<int>> skills;
        unordered_set<int> curTeam;
        ansTeam = {};
        teamSize = size(people) + 1;
        
        for (int i = 0; i < size(people); i++) {
            for (const string& skill: people[i]) {
                skills[skill].insert(i);
            }
        }
        
        dfs(req_skills, skills, 0, curTeam);
        
        return {begin(ansTeam), end(ansTeam)};
    }
    
    void dfs(
        vector<string>& rs,
        unordered_map<string, unordered_set<int>>& skills,
        int idx,
        unordered_set<int>& curTeam
    ) {
        if (size(curTeam) > teamSize) {
            return;
        }
        
        if (idx == size(rs)) {
            if (size(curTeam) < teamSize) {
                ansTeam = curTeam;
                teamSize = size(curTeam);
            }
            
            return;
        }
        
        for (int person: skills[rs[idx]]) {
            bool needToRemove = not curTeam.count(person);
            curTeam.insert(person);
            
            dfs(rs, skills, idx + 1, curTeam);
            
            if (needToRemove) {
                curTeam.erase(person);
            }
        }
    }
};