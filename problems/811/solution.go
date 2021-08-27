package main
func subdomainVisits(cpdomains []string) []string {
    outputMap := map[string]int{}
    outputArr := []string{}
    
    for _, cpdomain := range cpdomains {
        var count int
        var domain string
        
        fmt.Sscanf(cpdomain, "%d %s", &count, &domain)
        
        subdomains := strings.Split(domain, ".")
        subdLen := len(subdomains)
        
        for i := subdLen - 1; i >= 0; i-- {
            var ndomain = strings.Join(subdomains[i:subdLen], ".")
            
            outputMap[ndomain] += count
        }
    }
    
    for domain, count := range outputMap {
        outputArr = append(outputArr, fmt.Sprintf("%d %s", count, domain))
    }
    
    return outputArr
}