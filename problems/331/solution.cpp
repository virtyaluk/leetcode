class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        stringstream ss(preorder);
        string token;
        
        while (getline(ss, token, ',')) {
            slots--;
            
            if (slots < 0) {
                return false;
            }
            
            if (token != "#") {
                slots += 2;
            }
        }
        
        return slots == 0;
    }
};