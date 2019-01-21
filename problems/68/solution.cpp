class Solution {
private:
    string justifyLine(vector<string>& line, int runningLen, int maxWidth) {
        if (size(line) == 1) {
            return justifyLeft(line, maxWidth);
        }
        
        string ans;
        int spaces = maxWidth - runningLen,
            brakes = size(line) - 1,
            extra = spaces % brakes;
        
        for (const string& word: line) {
            ans += word + string(spaces / brakes + (extra-- > 0), ' ');
        }
        
        return ans.substr(0, maxWidth);
    }
    
    string justifyLeft(vector<string>& line, int width) {
        string ans;
        
        for (const string& word: line) {
            ans += word + " ";
        }
        
        if (size(ans) < width) {
            ans += string(width - size(ans), ' ');
        }
        
        return ans.substr(0, width);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans, line;
        int runningLen = 0;
        
        for (const string& word: words) {
            if (runningLen + size(word) + size(line) > maxWidth) {
                ans.push_back(justifyLine(line, runningLen, maxWidth));
                line.clear();
                runningLen = 0;
            }
            
            line.push_back(word);
            runningLen += size(word);
        }
        
        ans.push_back(justifyLeft(line, maxWidth));
        
        return ans;
    }
};