class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res(n);
        int nho = 1;
        int temp = 0;
        for(int i = n-1; i >= 0; i--) {
            temp = digits[i] + nho;
            if(temp >= 10) {
                nho = 1;
                res[i] = temp % 10;
            } else {
                nho = 0;
                res[i] = temp;
                for(int j = i - 1; j >= 0; j--) {
                    res[j] = digits[j];
                }
                break;
            }
        }
        if(nho) {
            res.insert(res.begin(), 1);
        }
        return res;
    }
};
