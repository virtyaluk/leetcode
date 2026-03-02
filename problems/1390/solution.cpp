class Solution {
private:
    int helper(int a) {
        int cnt = 0,
            sum = 1 + a;
        
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                cnt++;
                sum += i;

                if (i * i != a) {
                    cnt++;
                    sum += (a/i);
                }
            }
        }

        if ((cnt + 2) == 4) {
            return sum;
        }

        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (const int& num: nums) {
            ans += helper(num);
        }

        return ans;
    }
};