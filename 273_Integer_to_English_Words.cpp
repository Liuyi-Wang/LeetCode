class Solution {
public:
    string underTen(int num) {
        switch(num) {
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
        }
        return "?";
    }
    
    string underHundred(int num) {
        switch(num) {
            case 2:
                return "Twenty";
            case 3:
                return "Thirty";
            case 4:
                return "Forty";
            case 5:
                return "Fifty";
            case 6:
                return "Sixty";
            case 7:
                return "Seventy";
            case 8:
                return "Eighty";
            case 9:
                return "Ninety";
        }
        return "?";
    }
    
    string tens(int num) {
        switch(num) {
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
        }
        return "?";
    }
    
    string underThousand(int num) {
        string result;
        if (num >= 100) {
            result += underTen(num/100) + " Hundred";
            num %= 100;
        }
        if (num >= 20) {
            result += (result.size()==0?"":" ") + underHundred(num/10);
            num %= 10;
        } else if (num >= 10) {
            result += (result.size()==0?"":" ") + tens(num);
            num /= 100;
        }
        if (num > 0) {
            result += (result.size()==0?"":" ") + underTen(num);
        }
        return result;
    }
    
    string underMillion(int num) {
        string result;
        if (num/1000 > 0) {
            result = underThousand(num/1000);
            result += " Thousand";
        }
        if (num%1000 > 0) {
            result += (result.size()==0?"":" ") + underThousand(num%1000);
        }
        return result;
    }
    
    string underBillion(int num) {
        string result;
        if (num/1000000 > 0) {
            result = underThousand(num/1000000);
            result += " Million";
        }
        if (num%1000000 > 0) {
            result += (result.size()==0?"":" ") + underMillion(num%1000000);
        }
        return result;
    }
    
    string overBillion(int num) {
        string result;
        if (num/1000000000 > 0) {
            result = underThousand(num/1000000000);
            result += " Billion";
        }
        if (num%1000000000 > 0) {
            result += (result.size()==0?"":" ") + underBillion(num%1000000000);
        }
        return result;
    }
    
    string numberToWords(int num) {
        if (0 == num) {
            return "Zero";
        }
        if (num < 1000) {
            return underThousand(num);
        }
        if (num < 1000000) {
            return underMillion(num);
        }
        if (num < 1000000000) {
            return underBillion(num);
        }
        return overBillion(num);
    }
};
