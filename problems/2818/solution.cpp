const int MOD = 1e9 + 7;

class Solution {
private:
    long long power(long long base, long long exp) {
        long long ans = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = ((ans * base) % MOD);
            }

            base = (base * base) % MOD;
            exp /= 2;
        }

        return ans;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = size(nums);
        long long ans = 1;
        vector<int> scores(n),
            nextDominant(n, n),
            prevDominant(n, -1),
            st;
        vector<long long> nos(n);
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    scores[i]++;

                    while (num % factor == 0) {
                        num /= factor;
                    }
                }
            }

            if (num >= 2) {
                scores[i]++;
            }
        }

        for (int i = 0; i < n; i++) {
            while (not empty(st) and scores[st.back()] < scores[i]) {
                int topIdx = st.back();
                st.pop_back();
                nextDominant[topIdx] = i;
            }

            if (not empty(st)) {
                prevDominant[i] = st.back();
            }

            st.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            nos[i] = (long long) (nextDominant[i] - i) * (i - prevDominant[i]);
            pq.push({nums[i], i});
        }

        while (k > 0) {
            auto [num, idx] = pq.top();
            pq.pop();

            long long ops = min((long long) k, nos[idx]);
            ans = (ans * power(num, ops)) % MOD;
            k -= ops;
        }

        return ans;
    }
};