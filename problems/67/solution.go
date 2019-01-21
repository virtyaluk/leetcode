func addBinary(a string, b string) string {
    an, bn, res, carry := len(a) - 1, len(b) - 1, "", false
    
    for an >= 0 || bn >= 0 || carry {
        nch := 0
        
        if carry { nch++ }
        if an >= 0 && a[an] == '1' { nch++ }
        if bn >= 0 && b[bn] == '1' { nch++ }
        
        an--
        bn--
        carry = nch >= 2
        nch %= 2
        
        res = strconv.Itoa(nch) + res
    }
    
    return res
}