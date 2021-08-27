class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans;
        unordered_map<int, pair<int, string>> dict;
        
        for (int i = 0; i < size(indices); i++) {
            if (s.substr(indices[i], size(sources[i])) == sources[i]) {
                dict[indices[i]] = {size(sources[i]), targets[i]};
            }
        }
        
        for (int i = 0; i < size(s); i++) {
            if (dict.count(i)) {
                ans += dict[i].second;
                i += dict[i].first - 1;
            } else {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
    
    string findReplaceString1(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> repl;
        
        for (int i = 0; i < size(indices); i++) {
            repl.push_back({indices[i], i});
        }
        
        sort(begin(repl), end(repl), greater());
        
        for (auto [ind, origIdx]: repl) {
            int sourceLen = size(sources[origIdx]);
            
            if (sources[origIdx] != s.substr(ind, sourceLen)) {
                continue;
            }
            
            s = s.substr(0, ind) + targets[origIdx] + s.substr(ind + sourceLen);
        }
        
        return s;
    }
};

/*

abcd
0: a -> eee
2: cd -> ffff

eeebcd
eeebffff

*/