class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n == 0 || x == 1) return 1;
        int d = 1;
        long long power = n;
        if(n < 0) {
            d = 0;
            power = -power;
        }

        while(power > 0) {
            if(power&1) res*=x;
            x = x*x;
            power >>= 1;
        }

        return d == 1 ? res: 1/res;
    }
};
