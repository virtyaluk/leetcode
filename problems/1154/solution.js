const days = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334];

/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function(date) {
    let [year, month, day] = date.split('-');
    year = parseInt(year);
    month = parseInt(month);
    day = parseInt(day);
    let res = day;
    
    res += days[month - 1];
    
    if (month >= 3 && year > 1900 && year % 4 === 0) {
        res++;
    }
    
    return res;
};