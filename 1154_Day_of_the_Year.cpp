class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days(12, 0);
        days[1] = 31;
        days[2] = 59;
        days[3] = 90;
        days[4] = 120;
        days[5] = 151;
        days[6] = 181;
        days[7] = 212;
        days[8] = 243;
        days[9] = 273;
        days[10] = 304;
        days[11] = 334;
        
        int year, month, day;
        year = atoi(date.substr(0, 4).c_str());
        if ('0' == date[5]) {
            month = atoi(date.substr(6, 1).c_str());
        } else {
            month = atoi(date.substr(5, 2).c_str());
        }
        if ('0' == date[8]) {
            day = atoi(date.substr(9, 1).c_str());
        } else {
            day = atoi(date.substr(8, 2).c_str());
        }
        int result = 0;
        result += days[month-1];
        result += day;
        if (month > 2) {
            if (0 == year%100) {
                if (0 == year%400) {
                    ++result;
                }
            } else if (0 == year%4) {
                ++result;
            }
        }
        return result;
    }
};
