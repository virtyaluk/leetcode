class Solution {
public:
    
    string numberToWords(int num) {
        if (not num) {
            return "Zero";
        }
        
        string ans;
        
        int bil = num / 1e9,
            mil = (num - bil * 1e9) / 1e6,
            thous = (num - bil * 1e9 - mil * 1e6) / 1e3,
            rest = (num - bil * 1e9 - mil * 1e6 - thous * 1e3);
        
        if (bil) {
            ans += helper1(bil) + " Billion";
        }
        
        if (mil) {
            if (not empty(ans)) {
                ans.push_back(' ');
            }
            
            ans += helper1(mil) + " Million";
        }
        
        if (thous) {
            if (not empty(ans)) {
                ans.push_back(' ');
            }

            ans += helper1(thous) + " Thousand";
        }
        
        if (rest) {
            if (not empty(ans)) {
                ans.push_back(' ');
            }

            ans += helper1(rest);
        }
        
        return ans;
    }
    
    string helper1(int num) {
        string ans;
        
        int hund = num / 100,
            tens = num - hund * 100;
        
        if (hund) {
            ans += helperOnes(hund) + " Hundred";
        }
        

        if (tens) {
            if (not empty(ans)) {
                ans.push_back(' ');
            }
            
            if (tens >= 20) {
                ans += helperTens(tens / 10);
                
                if (tens % 10) {
                    ans += " " + helperOnes(tens % 10);
                }
            } else if (tens >= 10) {
                ans += helperLess20(tens);
            } else {
                ans += helperOnes(tens % 10);
            }
        }
        
        return ans;
    }
    
    string helperOnes(int num) {
        switch (num) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        
        return "";
    }
    
    string helperTens(int num) {
        switch (num) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
        }
        
        return "";
    }
    
    string helperLess20(int num) {
        switch (num) {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        
        return "";
    }
};