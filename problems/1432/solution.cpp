class Solution {
private:
    void replace(string& s, char x, char y = '9') {
        for (char& ch: s) {
            if (ch == x) {
                ch = y;
            }
        }
    }
public:
    int maxDiff(int num) {
        string m = to_string(num),
            M = to_string(num);

        for (const char& ch: M) {
            if (ch != '9') {
                replace(M, ch);
                break;
            }
        }

        for (int i = 0; i < size(m); i++) {
            char ch = m[i];

            if (i == 0) {
                if (ch != '1') {
                    replace(m, ch, '1');
                    break;
                }
            } else {
                if (ch != '0' and ch != m.front()) {
                    replace(m, ch, '0');
                    break;
                }
            }
        }

        return stoi(M) - stoi(m);
    }
};