class Solution:
    def reformatDate(self, date: str) -> str:
        months = {
            'Jan': '01',
            'Feb': '02',
            'Mar': '03',
            'Apr': '04',
            'May': '05',
            'Jun': '06',
            'Jul': '07',
            'Aug': '08',
            'Sep': '09',
            'Oct': '10',
            'Nov': '11',
            'Dec': '12'
        }
        parts = date.split(' ')
        day = int(''.join([d for d in parts[0] if d.isdigit()]))
        
        return f'{parts[-1]}-{months[parts[1]]}-{day:02d}';