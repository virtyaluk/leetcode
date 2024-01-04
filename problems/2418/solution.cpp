class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int, string>> people;
        
        for (int i = 0; i < size(names); i++) {
            people.push_back({
                heights[i],
                names[i]
            });
        }
        
        sort(begin(people), end(people), greater<>());
        
        for (auto [ignore, name]: people) {
            ans.push_back(name);
        }
        
        return ans;
    }
};