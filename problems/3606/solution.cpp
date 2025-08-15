class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<tuple<int, string>> valid;
        vector<string> ans;
        unordered_map<string, int> order = {
            {"electronics", 1},
            {"grocery", 2},
            {"pharmacy", 3},
            {"restaurant", 4},
        };

        for (int i = 0; i < size(code); i++) {
            if (not isActive[i]) {
                continue;
            }

            if (not order.count(businessLine[i])) {
                continue;
            }

            if (empty(code[i]) or size(code[i]) != count_if(begin(code[i]), end(code[i]), [](const char& ch) {
                return isalnum(ch) or ch == '_';
            })) {
                continue;
            }

            valid.push_back({order[businessLine[i]], code[i]});
        }

        sort(begin(valid), end(valid));

        for (auto& [_, c]: valid) {
            ans.push_back(c);
        }

        return ans;
    }
};