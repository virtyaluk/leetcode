class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;

        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }

        sort(begin(nums), end(nums), greater());

        return nums[0] * nums[1];
    }
};