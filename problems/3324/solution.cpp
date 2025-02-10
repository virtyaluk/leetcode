class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        
        while (not empty(target)) {
            ans.push_back(target);
            
            if (target.back() == 'a') {
                target.pop_back();
            } else {
                target.back()--;
            }
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};