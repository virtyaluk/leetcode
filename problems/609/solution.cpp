class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, unordered_set<string>> um;
        
        for (const string& path: paths) {
            istringstream iss(path);
            vector<string> files{istream_iterator<string>{iss}, istream_iterator<string>{}};
            
            // copy(begin(files), end(files), ostream_iterator<string>(cout, ", "));
            // cout << endl;
            
            for (int i = 1; i < files.size(); i++) {
                int openParentheses = files[i].find('(');
                
                string fileName = files[i].substr(0, openParentheses),
                    fileContents = files[i].substr(openParentheses + 1, files[i].size() - 1 - openParentheses - 1);
                
                um[fileContents].insert(files[0] + "/" + fileName);
            }
        }
        
        for (auto &[ignore, group]: um) {
            if (group.size() > 1) {
                ans.push_back({begin(group), end(group)});
            }
        }
        
        return ans;
    }
};