class Solution {
public:
    int myAtoi(string s) {
        int MAX = INT_MAX, MIN = INT_MIN;
        int i = 0; 
        while(s[i] == ' ') i++;
        int d = 1;
        if(s[i] == '-') {
            d = -1;
            i++;
        }
        else if(s[i] == '+') {
            i++;
        }
        long res = 0;
        while(s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
            // Handle overflow/underflow
            if (d == 1 && res > MAX) return MAX;
            if (d == -1 && -res < MIN) return MIN;
            i++;
        }
        return (int)(res*d);
    }
};
