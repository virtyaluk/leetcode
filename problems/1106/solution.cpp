class Solution {
private:
    void eval(stack<pair<char, vector<bool>>>& st) {
        auto [op, operands] = st.top();
        bool ans = operands.front();
        
        st.pop();
        
        if (op == '!') {
            ans = !ans;
        } else {
            for (int i = 1; i < size(operands); i++) {
                if (op == '|') {
                    ans |= operands[i];
                } else if (op == '&') {
                    ans &= operands[i];
                }
            }
        }
        
        st.top().second.push_back(ans);
    }
public:
    bool parseBoolExpr(string ex) {
        stack<pair<char, vector<bool>>> st;
        
        st.push({'#', {}});
        
        for (const char& ch: ex) {
            if (ch == 't') {
                st.top().second.push_back(true);
            } else if (ch == 'f') {
                st.top().second.push_back(false);
            } else if (ch == '|' or ch == '&' or ch == '!') {
                st.push({ch, {}});
            } else if (ch == ')') {
                eval(st);
            }
        }
        
        return st.top().second.front();
    }
};