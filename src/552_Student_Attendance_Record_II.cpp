/**
 *	Time:
 *	O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int MODULE = 1e9+7;
    
    int checkRecord(int n) {
        int dp00 = 1;
        int dp01 = 1;
        int dp02 = 0;
        int dp10 = 1;
        int dp11 = 0;
        int dp12 = 0;
        for (int i = 1; i < n; ++i) {
            int dpi00 = 0;
            int dpi01 = 0;
            int dpi02 = 0;
            int dpi10 = 0;
            int dpi11 = 0;
            int dpi12 = 0;
            dpi00 = (dpi00+dp00)%MODULE;
            dpi00 = (dpi00+dp01)%MODULE;
            dpi00 = (dpi00+dp02)%MODULE;
            
            dpi01 = dp00;
            dpi02 = dp01;
            
            dpi10 = (dpi10+dp10)%MODULE;
            dpi10 = (dpi10+dp11)%MODULE;
            dpi10 = (dpi10+dp12)%MODULE;
            dpi10 = (dpi10+dp00)%MODULE;
            dpi10 = (dpi10+dp01)%MODULE;
            dpi10 = (dpi10+dp02)%MODULE;
            
            dpi11 = dp10;
            dpi12 = dp11;
            
            dp00 = dpi00;
            dp01 = dpi01;
            dp02 = dpi02;
            dp10 = dpi10;
            dp11 = dpi11;
            dp12 = dpi12;
        }
        int result = 0;
        result = (result+dp00)%MODULE;
        result = (result+dp01)%MODULE;
        result = (result+dp02)%MODULE;
        result = (result+dp10)%MODULE;
        result = (result+dp11)%MODULE;
        result = (result+dp12)%MODULE;
        return result;
    }
};
