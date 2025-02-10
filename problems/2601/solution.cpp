class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> sieve(maxEl + 1, 1);
        sieve[1] = 0;
        
        for (int i = 2; i < sqrt(maxEl + 1); i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= maxEl; j+= i) {
                    sieve[j] = 0;
                }
            }
        }
        
        for (int i = 0, cur = 1; i < size(nums);) {
            int dif = nums[i] - cur;
            
            if (dif < 0) {
                return 0;
            }
            
            if (sieve[dif] == 1 or dif == 0) {
                i++;
                cur++;
            } else {
                cur++;
            }
        }
        
        return true;
    }
};