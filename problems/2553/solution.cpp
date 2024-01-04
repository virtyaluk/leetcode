class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        for (int num: nums) {
            vector<int> sub;
            
            while (num) {
                sub.push_back(num % 10);
                num /= 10;
            }
            
            ans.insert(end(ans), rbegin(sub), rend(sub));
        }
        
        return ans;
    }
};