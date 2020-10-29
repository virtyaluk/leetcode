class Solution {
public:
    string parseTernary(string expression) {
        int pos = 0;
        return parse(expression, pos);
    }
    
    string parse(string& exp, int& pos) {
        int origPos = pos;
        
        if (pos + 1 < size(exp) and exp[pos + 1] == '?') {
            pos += 2;
            string a = parse(exp, pos), b = parse(exp, ++pos);
            
            return exp[origPos] == 'T' ? a : b;
        }
        
        return exp.substr(pos++, 1);
    }
};