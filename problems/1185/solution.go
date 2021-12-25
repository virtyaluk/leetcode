package main
// https://en.wikipedia.org/wiki/Zeller%27s_congruence

func dayOfTheWeek(day int, month int, year int) string {
    if month <= 2 {
        year--
        month += 12
    }
    
    k, j := year % 100, year / 100
    h := (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7
    
    return []string{"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}[h]
}