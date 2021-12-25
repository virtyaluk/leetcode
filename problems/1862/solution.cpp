const int MOD = 1e9 + 7;

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        long long int ans = 0;
        int maxNum = *max_element(begin(nums), end(nums));
        vector<long long int> freq(maxNum + 1),
            prefSum(maxNum + 1);
        
        for (const int& num: nums) {
            freq[num]++;
        }
        
        for (int i = 1; i <= maxNum; i++) {
            prefSum[i] = prefSum[i - 1] + freq[i];
        }
        
        for (int i = 0; i <= maxNum; i++) {
            if (freq[i]) {
                int k = 1,
                    kNext;
                
                do {
                    kNext = k + 1;
                    int right = min(kNext * i - 1, maxNum),
                        left = k * i - 1;
                    
                    ans += (prefSum[right] - prefSum[left]) * freq[i] * k++;
                } while (kNext * i - 1 < maxNum);
            }
        }
        
        return ans % MOD;
    }
};