class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (size(s) % 2 == 1) {
            return false;
        }

        stack<int> open, unlocked;

        for (int i = 0; i < size(s); i++) {
            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (not empty(open)) {
                    open.pop();
                } else if (not empty(unlocked)) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        while (not empty(open) and not empty(unlocked) and open.top() < unlocked.top()) {
            open.pop();
            unlocked.pop();
        }
        
        if (not empty(open)) {
            return false;
        }

        return true;
    }
};