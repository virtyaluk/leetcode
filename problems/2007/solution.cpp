class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = size(changed);
        vector<int> ans;
        unordered_map<int, int> freq;
        
        if (n % 2 != 0) {
            return ans;
        }
        
        sort(begin(changed), end(changed));
        
        for (const int& num: changed) {
            freq[num]++;
        }
        
        for (const int& num: changed) {
            if (freq[num]) {
                freq[num]--;
                
                if (freq[num * 2]) {
                    freq[num * 2]--;
                    ans.push_back(num);
                } else {
                    return {};
                }
            }
        }
        
        return ans;
    }
};