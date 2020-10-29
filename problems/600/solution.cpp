vector<int> nums;

class Solution {
public:
    int findIntegers(int n) {
        if (empty(nums)) {
            nums = {0, 1};
            int i = 1, MAX = pow(10, 9);

            while (i < size(nums)) {
                int cur = nums[i];

                if (cur * 2 <= MAX) {
                    nums.push_back(cur * 2);
                }

                if (cur % 2 == 0 and cur * 2 + 1 <= MAX) {
                    nums.push_back(cur * 2 + 1);
                }

                i++;
            }
        }
        
        return distance(begin(nums), upper_bound(begin(nums), end(nums), n));
    }
    int findIntegers1(int n) {
        int ans = 0;
        vector<int> fib(32);
        fib[0] = 1;
        fib[1] = 2;
        
        for (int i = 2; i < 32; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        for (int k = 30, prevBitIs1 = 0; k >= 0; k--) {
            if (n & (1 << k)) {
                ans += fib[k];
                
                if (prevBitIs1) {
                    return ans;
                }
                
                prevBitIs1 = true;
            } else {
                prevBitIs1 = false;
            }
        }
        
        return ans + 1;
    }
};