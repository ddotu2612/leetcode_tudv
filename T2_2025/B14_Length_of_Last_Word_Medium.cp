class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        while(s[n-1] == ' ') n--;
        int res = 0;
        while(n-1 >= 0 && s[n-1] != ' ') {
            n--;
            res++;
        }
        return res;
    }
};
