class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j = 0, k = 0;
        
        for (const int& num: pushed) {
            pushed[k] = num;
            
            while (j < n and k >= 0 and pushed[k] == popped[j]) {
                k--;
                j++;
            }
            
            k++;
        }
        
        return j >= n;
    }
    
    bool validateStackSequences2(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0, n = pushed.size();
        
        while (true) {
            if (j < n and not st.empty() and popped[j] == st.top()) {
                j++;
                st.pop();
            } else if (i < n) {
                st.push(pushed[i++]);
            } else {
                break;
            }
        }
        
        return j >= n;
    }
    
    bool validateStackSequences1(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size(), i = 0;

        for (int num: pushed) {
            st.push(num);
            
            while (!st.empty() && i < n && st.top() == popped[i]) {
                st.pop();
                i++;
            }
        }

        return i == n;
    }
};