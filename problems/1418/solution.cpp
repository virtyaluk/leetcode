class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        unordered_map<string, unordered_map<string, int>> um;
        set<string> foodNames;
        
        for (const vector<string>& order: orders) {
            string tableNumber = order[1],
                foodItem = order[2];
            
            um[tableNumber][foodItem]++;
            foodNames.insert(foodItem);
        }
        
        ans.push_back({"Table"});
        
        for (const string& food: foodNames) {
            ans.back().push_back(food);
        }
        
        for (auto [tableNumber, foods]: um) {
            ans.push_back({tableNumber});
            
            for (const string& foodItem: foodNames) {
                ans.back().push_back(to_string(foods[foodItem]));
            }
        }
        
        sort(begin(ans) + 1, end(ans), [](auto& lhs, auto& rhs) {
            return stoi(lhs.front()) < stoi(rhs.front());
        });
        
        return ans;
    }
};