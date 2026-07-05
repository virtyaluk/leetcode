struct State {
    int prev, cur, tight, lead;
    long long cnt, sum;
};

class Solution {
private:
    long long solve(long long num) {
        if (num < 100) {
            return 0;
        }

        string s = to_string(num);
        int n = size(s);
        vector<State> curStates;

        curStates.push_back({10, 10, 1, 1, 1, 0});

        for (int pos = 0; pos < n; pos++) {
            int limit = s[pos] - '0';
            long long cnt[2][2][11][11] = {0};
            long long sum[2][2][11][11] = {0};

            for (const auto& st: curStates) {
                int maxDigit = st.tight ? limit : 9;

                for (int digit = 0; digit <= maxDigit; digit++) {
                    int newLead = st.lead and (digit == 0),
                        newPrev = st.cur,
                        newCur = newLead ? 10 : digit,
                        newTight = st.tight and (digit == maxDigit);
                    long long add = 0;
                
                    if (not newLead and st.prev != 10 and st.cur != 10) {
                        if ((st.prev < st.cur and st.cur > digit) or (st.prev > st.cur and st.cur < digit)) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCur] += st.cnt;
                    sum[newTight][newLead][newPrev][newCur] += st.sum + add;
                }
            }

            vector<State> nextStates;

            for (int tight = 0; tight < 2; tight++) {
                for (int lead = 0; lead < 2; lead++) {
                    for (int prev = 0; prev <= 10; prev++) {
                        for (int cur = 0; cur <= 10; cur++) {
                            long long c = cnt[tight][lead][prev][cur],
                                s = sum[tight][lead][prev][cur];
                            
                            if (c != 0) {
                                nextStates.push_back({prev, cur, tight, lead, c, s});
                            }
                        }
                    }
                }
            }

            curStates.swap(nextStates);
        }

        long long ans = 0;

        for (const auto& st: curStates) {
            ans += st.sum;
        }

        return ans;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};