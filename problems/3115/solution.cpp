class Solution {
private:
    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }

        if (x == 2 or x == 3) {
            return true;
        }

        if (x % 2 == 0) {
            return false;
        }

        for (int i = 3; i * i <= x; i+= 2) {
            if (x % i == 0) {
                return false;
            }
        }

        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1,
            last = -1;
        
        for (int i = 0; i < size(nums); i++) {
            if (isPrime(nums[i])) {
                if (first == -1) {
                    first = i;
                }

                last = i;
            }
        }

        return first == -1 ? 0 : last - first;
    }
};