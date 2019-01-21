public class Solution {
    public string AddBinary(string a, string b) {
        var an = a.Length - 1;
        var bn = b.Length - 1;
        var carry = false;
        var res = "";
        
        while (an >= 0 || bn >= 0) {
            var nch = carry ? 1 : 0;
            nch += an >= 0 && a[an] == '1' ? 1 : 0;
            nch += bn >= 0 && b[bn] == '1' ? 1 : 0;
            an--;
            bn--;
            carry = nch >= 2;
            nch -= carry ? 2 : 0;
            
            res = nch.ToString() + res;
        }
        
        if (carry) {
            res = "1" + res;
        }
        
        return res;
    }
}