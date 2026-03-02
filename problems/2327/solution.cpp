const int MOD = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 1,
            shared = 0;
        deque<pair<int, int>> know, share;
        know.emplace_back(1, 1);

        for (int i = 2; i <= n; i++) {
            if (not empty(know) and know.front().first == i - delay) {
                ans = (ans - know.front().second + MOD) % MOD;
                shared = (shared + know.front().second) % MOD;
                share.push_back(know.front());
                know.pop_front();
            }

            if (not empty(share) and share.front().first == i - forget) {
                shared = (shared - share.front().second + MOD) % MOD;
                share.pop_front();
            }

            if (not empty(share)) {
                ans = (ans + shared) % MOD;
                know.emplace_back(i, shared);
            }
        }

        return (ans + shared) % MOD;
    }
};