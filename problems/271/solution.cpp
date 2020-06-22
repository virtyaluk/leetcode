const char DELIMITER = '\0';

class Codec {    
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        
        for (const string str: strs) {
            ans += str + DELIMITER;
        }
        
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        stringstream iss(s);
        string token;
        
        while (getline(iss, token, DELIMITER)) {
            ans.push_back(token);
        }
        
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));