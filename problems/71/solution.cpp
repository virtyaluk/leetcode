class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token, ans;
        vector<string> sub;
        
        while (getline(ss, token, '/')) {
            if (token == "" or token == ".") {
                continue;
            } else if (token == "..") {
                if (not empty(sub)) {
                    sub.pop_back();
                }
            } else {
                sub.push_back("/" + token);
            }
        }
        
        for (const string& subPath: sub) {
            ans += subPath;
        }
        
        if (empty(ans)) {
            return "/";
        }
        
        return ans;
    }
};