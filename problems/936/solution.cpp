class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int ns = stamp.size(), nt = target.size();
        vector<int> ans;
        bool ok = true;
        
        do {
            ok = false;
            
            for (int i = 0; i <= nt - ns; i++) {
                bool found = true;
                int dots = 0;
                
                for (int j = 0; j < ns; j++) {
                    if (target[i + j] == '.') {
                        dots++;
                    } else if (stamp[j] != target[i + j]) {
                        found = false;
                        break;
                    }
                }
                
                if (found and dots < ns) {
                    ok = true;
                    ans.push_back(i);
                    
                    for (int j = 0; j < ns; j++) {
                        target[i + j] = '.';
                    }
                }
            }
        } while (ok);
        
        if (any_of(begin(target), end(target), [](const char& ch) { return ch != '.'; })) {
            return {};
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};

/*

abc - [2, 0]
ababc -> ab??? -> ?????


abca - [1, 0, 3]
aabcaca -> a????ca -> ?????ca -> ???????
*/