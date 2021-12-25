class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (size(nums) % k != 0) {
            return false;
        }
        
        unordered_map<int, int> freq;
        
        for (const int& num: nums) {
            freq[num]++;
        }
        
        for (const int& num: nums) {
            int start = num;
            
            while (freq[start - 1] > 0) {
                start--;
            }
            
            while (freq[start]) {
                for (int i = start; i < start + k; i++) {
                    if (not freq[i]) {
                        return false;
                    }
                    
                    freq[i]--;
                }
            }
        }
        
        return true;
    }
};