class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        
        for (char ch: s) {
            if (ch == ' ') {
                continue;
            }
            
            q.push(ch);
        }
        
        q.push('+');
        
        return calc(q);
    }
    
    int calc(queue<char> &q) {
        int ans = 0;
        long long int lastNum = 0;
        char lastOp = '+';
        stack<long long int> st;
        
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            
            if (ch == '(') {
                lastNum = calc(q);
            } else if (isdigit(ch)) {
                lastNum = lastNum * 10 + ch - '0';
            } else {
                int stTop = 0;

                switch (lastOp) {
                    case '+':
                        st.push(lastNum);
                        break;
                    case '-':
                        st.push(-lastNum);
                        break;
                    case '/':
                        stTop = st.top();
                        
                        st.pop();
                        st.push(stTop / lastNum);
                        break;
                    case '*':
                        stTop = st.top();
                        
                        st.pop();
                        st.push(stTop * lastNum);
                        break;
                }
                
                if (ch == ')') {
                    break;
                }
                
                lastOp = ch;
                lastNum = 0;
            }
        }
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};