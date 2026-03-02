class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers),
            nextOnlineTime(numberOfUsers);
        
        sort(begin(events), end(events), [&](const vector<string>& lhs, const vector<string>& rhs) {
            int lhsTs = stoi(lhs[1]),
                rhsTs = stoi(rhs[1]);

            if (lhsTs != rhsTs) {
                return lhsTs < rhsTs;
            }

            if (rhs[0] == "OFFLINE") {
                return false;
            }

            return true;
        });

        for (auto&& e: events) {
            int curTs = stoi(e[1]);

            if (e[0] == "MESSAGE") {
                if (e[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        ans[i]++;
                    }
                } else if (e[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (nextOnlineTime[i] <= curTs) {
                            ans[i]++;
                        }
                    }
                } else {
                    int idx = 0;

                    for (int i = 0; i < size(e[2]); i++) {
                        if (isdigit(e[2][i])) {
                            idx = idx * 10 + (e[2][i] - '0');
                        }

                        if (i + 1 == size(e[2]) or e[2][i + 1] == ' ') {
                            ans[idx]++;
                            idx=0;
                        }
                    }
                }
            } else {
                int idx = stoi(e[2]);
                nextOnlineTime[idx] = curTs + 60;
            }
        }

        return ans;
    }
};