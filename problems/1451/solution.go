package main
import "strings"
import "sort"

func arrangeWords(text string) string {
    m, ans := make(map[int][]string), ""
    
    for _, v := range strings.Split(text, " ") {
        l := len(v)
        m[l] = append(m[l], strings.ToLower(v))
    }
    
    ks := make([]int, 0, len(m))
    
    for k := range m {
        ks = append(ks, k)
    }
    
    sort.Ints(ks[:])
    
    for _, v := range ks {
        if len(ans) > 0 {
            ans += " "
        }
        
        ans += strings.Join(m[v], " ")
    }
    
    if len(ans) <= 1 {
        return strings.Title(ans)
    }
    
    return strings.Title(ans[0:1]) + ans[1:]
}