class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = size(digits),
            num;
        unordered_set<int> us;

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                for (int k = 0; k < n; k++) {
                    if (k == i or k == j or digits[k] % 2 != 0) {
                        continue;
                    }

                    num = digits[i] * 100;
                    num += digits[j] * 10;
                    num += digits[k];

                    us.insert(num);
                }
            }
        }

        return size(us);
    }
};