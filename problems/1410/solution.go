package main
const (
    quot = "&quot;"
    apos = "&apos;"
    amp = "&amp;"
    gt = "&gt;"
    lt = "&lt;"
    frasl = "&frasl;"
)

func entityParser(text string) string {
    ans := ""
    n := len(text)
    
    for i := 0; i < n; i++ {
        if text[i] == '&' {
            if i + len(quot) <= n && text[i:i + len(quot)] == quot {
                ans += `"`
                i += len(quot) - 1
            } else if i + len(apos) <= n && text[i:i + len(apos)] == apos {
                ans += `'`
                i += len(apos) - 1
            } else if i + len(amp) <= n && text[i:i + len(amp)] == amp {
                ans += "&"
                i += len(amp) - 1
            } else if i + len(gt) <= n && text[i:i + len(gt)] == gt {
                ans += ">"
                i += len(gt) - 1
            } else if i + len(lt) <= n && text[i:i + len(lt)] == lt {
                ans += "<"
                i += len(lt) - 1
            } else if i + len(frasl) <= n && text[i:i + len(frasl)] == frasl {
                ans += `/`
                i += len(frasl) - 1
            } else {
                ans += string(text[i])
            }
        } else {
            ans += string(text[i])
        }
    }
    
    return ans
}