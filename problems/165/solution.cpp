class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        istringstream iss1(version1), iss2(version2);
        string temp;
        
        while(getline(iss1, temp, '.')) v1.push_back(stoi(temp, nullptr, 10));
        while(getline(iss2, temp, '.')) v2.push_back(stoi(temp, nullptr, 10));
        
        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int sv1 = 0, sv2 = 0;
            
            if (i < v1.size()) {
                sv1 = v1[i];
            }
            
            if (i < v2.size()) {
                sv2 = v2[i];
            }
            
            if (sv1 > sv2) {
                return 1;
            } else if (sv1 < sv2) {
                return -1;
            }
        }
        
        return 0;
    }
};