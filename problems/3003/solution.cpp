class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = size(s),
            num = 0,
            mask = 0,
            count = 0,
            ans = 0;
        vector<vector<int>> left(n, vector<int>(3)),
            right(n, vector<int>(3));
        
        for (int i = 0; i < n - 1; i++) {
            int binary = 1 << (s[i] - 'a');

            if (not (mask & binary)) {
                count++;

                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }

            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        num = 0;
        mask = 0;
        count = 0;

        for (int i = n - 1; i > 0; i--) {
            int binary = 1 << (s[i] - 'a');

            if (not (mask & binary)) {
                count++;

                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }

            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        for (int i = 0; i < n; i++) {
            int seg = left[i][0] + right[i][0] + 2,
                totMask = left[i][1] | right[i][1],
                total = 0;
            
            while (totMask) {
                totMask = totMask & (totMask - 1);
                total++;
            }

            if (left[i][2] == k and right[i][2] == k and total < 26) {
                seg++;
            } else if (min(total + 1, 26) <= k) {
                seg--;
            }

            ans = max(ans, seg);
        }

        return ans;
    }
};