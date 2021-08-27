class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if (empty(emails)) {
            return 0;
        }
        
        unordered_set<string> ans;
        
        for (const string& email: emails) {
            istringstream iss(email);
            string name, domain;
            int j = 0;
            
            getline(iss, name, '@');
            getline(iss, domain, '@');
            
            for (int i = 0; i < size(name); i++) {
                name[j] = name[i];
                
                if (name[j] == '+') {
                    break;
                }
                
                if (name[i] != '.') {
                    j++;
                }
            }
            
            name = name.substr(0, j);
            
            ans.insert(name + "@" + domain);
        }
        
        return size(ans);
    }
};