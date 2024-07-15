class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int ans = 0,
            allApples = accumulate(begin(apple), end(apple), 0);
        
        sort(begin(capacity), end(capacity), greater<>());
        
        for (int i = 0; i < size(capacity) and allApples > 0; i++) {
            allApples -= capacity[i];
            ans++;
        }
        
        return ans;
    }
};