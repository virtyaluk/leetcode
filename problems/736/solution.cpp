typedef unordered_map<string, int> scope;

class Solution {
private:
    void skipSpaces(istringstream& iss) {
        while (iss.good() and isblank(iss.peek())) {
            iss.get();
        }
    }
    
    bool isNumber(istringstream& iss) {
        skipSpaces(iss);
        
        return isdigit(iss.peek()) or iss.peek() == '-';
    }
    
    bool isExp(istringstream& iss) {
        skipSpaces(iss);
        
        return iss.peek() == '(';
    }
    
    bool isValue(istringstream& iss) {
        return isNumber(iss) or isExp(iss);
    }
    
    string getToken(istringstream& iss) {
        skipSpaces(iss);
        ostringstream ans;
        
        while (iss.good() and isalnum(iss.peek())) {
            ans << iss.get();
        }
        
        return ans.str();
    }
    
    int getValue(istringstream& iss, scope tokens) {
        if (isNumber(iss)) {
            int val;
            iss >> val;
            
            return val;
        }
        
        if (isExp(iss)) {
            return parseExp(iss, tokens);
        }
        
        return tokens[getToken(iss)];
    }
    
    int parseExp(istringstream& iss, scope tokens = {}) {
        iss.get();
        
        int ans = 0;
        string token;
        
        iss >> token;
        
        if (token == "add") {
            ans = getValue(iss, tokens) + getValue(iss, tokens);
        }
        
        if (token == "mult") {
            ans = getValue(iss, tokens) * getValue(iss, tokens);
        }
        
        if (token == "let") {
            while (not isValue(iss)) {
                string varName = getToken(iss);
                
                if (iss.peek() == ')') {
                    ans = tokens[varName];
                    break;
                }
                
                tokens[varName] = getValue(iss, tokens);
            }
            
            if (isValue(iss)) {
                ans = getValue(iss, tokens);
            }
        }
        
        iss.get();
        return ans;
    }
    
public:
    int evaluate(string expression) {
        istringstream iss(expression);
        
        return parseExp(iss);
    }
};