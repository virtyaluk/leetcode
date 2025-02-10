class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        
        vector<string> ans{folder.front()};
        
        for (int i = 1; i < size(folder); i++) {
            string last = ans.back();
            last.push_back('/');
            
            if (folder[i].compare(0, size(last), last) != 0) {
                ans.push_back(folder[i]);
            }
        }
        
        return ans;
    }
};