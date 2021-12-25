from datetime import date

class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        f_date = date.fromisoformat(date2)
        l_date = date.fromisoformat(date1)
        delta = l_date - f_date

        return abs(delta.days)