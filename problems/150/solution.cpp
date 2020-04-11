class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int(int, int)>> ops = {
            {"+", [](const int& lhs, const int& rhs) { return lhs + rhs; }},
            {"*", [](const int& lhs, const int& rhs) { return lhs * rhs; }},
            {"/", [](const int& lhs, const int& rhs) { return lhs / rhs; }},
            {"-", [](const int& lhs, const int& rhs) { return lhs - rhs; }}
        };
        
        for (const string& token: tokens) {
            if (not ops.count(token)) {
                st.push(stoi(token));
            } else {
                int rhs = st.top();
                st.pop();
                int lhs = st.top();
                st.pop();
                
                st.push(ops[token](lhs, rhs));
            }
        }
        
        return st.top();
    }
    
    int evalRPN1(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        
        string last = tokens.back();
        tokens.pop_back();
        
        if (last != "*" and last != "/" and last != "-" and last != "+") {
            return stoi(last);
        }
        
        int rhs = evalRPN(tokens),
            lhs = evalRPN(tokens);
        
        if (last == "*") {
            return lhs * rhs;
        } else if (last == "/") {
            return lhs / rhs;
        } else if (last == "-") {
            return lhs - rhs;
        }
        
        return lhs + rhs;
    }
};