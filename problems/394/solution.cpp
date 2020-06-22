class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return decode(s, pos);
    }
    
    string decode(string s, int& pos) {
        stringstream ss;
        int k = 0;
        
        while (pos < s.size()) {
            char ch = s[pos];
            pos++;

            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == ']') {
                break;
            } else if (ch == '[') {
                string substr = decode(s, pos);
                
                while (k) {
                    ss << substr;
                    k--;
                }
            } else {
                ss << ch;
            }
        }
        
        return ss.str();
    }
    
    string decode1(queue<char>& q) {
        stringstream ss;
        int k = 0;
        
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                ss << repeat(decode1(q), k);
                k = 0;
            } else if (ch == ']') {
                break;
            } else {
                ss << ch;
            }
        }
        
        return ss.str();
    }
    
    string repeat(string s, int n) {
        stringstream ss;
        
        while (n--) {
            ss << s;
        }
        
        return ss.str();
    }
};