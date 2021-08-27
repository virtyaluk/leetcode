package main
func numUniqueEmails(emails []string) int {
    sentEmails := make(map[string]int)

	for _, email := range emails {
		domain := strings.Split(email, "@")[1]
		name := strings.Split(email, "@")[0]
		name = strings.Split(name, "+")[0]
		name = strings.Replace(name, ".", "", -1)

		sentEmails[name+"@"+domain]++
	}
	return len(sentEmails)
}