class Solution {
private:
    bool can_partition(int num, int target) {
        if (target < 0 or num < target) {
            return false;
        }

        if (num == target) {
            return true;
        }

        return can_partition(num / 10, target - num % 10)
            or can_partition(num / 100, target - num % 100)
            or can_partition(num / 1000, target - num % 1000);
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int sqrNum = i * i;

            if (can_partition(sqrNum, i)) {
                ans += sqrNum;
            }
        }

        return ans;
    }
};