class Solution {
public:
    int calculate(string s) {
        int ans = 0, i = 0;
        long long int lastNum = 0;
        char lastOp = '.';
        stack<long long int> st;
        
        while (i <= s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            
            if (s[i] == '(') {
                int j = i + 1, toggle = 1;
                
                while (j < s.size()) {
                    if (s[j] == '(') {
                        toggle++;
                    } else if (s[j] == ')') {
                        toggle--;
                    }
                    
                    if (s[j] == ')' && toggle == 0) {
                        break;
                    }
                    
                    j++;
                }

                
                lastNum = calculate(s.substr(i + 1, j - i - 1));
                i = j;
            } else if (s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+') {
                callOp(&st, &lastNum, &lastOp);
                lastOp = s[i];
            } else if (s[i] >= '0' && s[i] <= '9') {
                lastNum = lastNum * 10 + (s[i] - '0');
            } else if (s[i] == ')' || i == s.size()) {
                callOp(&st, &lastNum, &lastOp);
            }
            
            i++;
        }
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
    
    void callOp(stack<long long int> *st, long long int *lastNum, char *lastOp) {
        if (*lastOp == '*' || *lastOp == '/') {
            long long int prevNum = st->top();
            st->pop();
            
            if (*lastOp == '*') {
                *lastNum = prevNum * *lastNum;
            } else {
                *lastNum = prevNum / *lastNum;
            }
        } else if (*lastOp == '-') {
            *lastNum *= -1;
        }
        
        st->push(*lastNum);        
        *lastNum = 0;
        *lastOp = '.';
    }
};