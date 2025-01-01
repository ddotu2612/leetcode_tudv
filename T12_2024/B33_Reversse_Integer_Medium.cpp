class Solution {
public:
    int reverse(int x) {
        int d = 1;
        if(x < 0) d = -1;
        long long t = (long long) x * d;
        long long res = 0;
        while (t > 9) {
            res += t % 10;
            res = res*10;
            t = t/10;
        }
        if(res + t > INT_MAX) return 0; 
        return (int)((res + t) * d);
    }
};
