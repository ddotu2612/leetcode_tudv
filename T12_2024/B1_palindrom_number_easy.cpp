class Solution {
public:
    bool isPalindrome(int x) {
        auto s = to_string(x);
        if(x < 0) return false;
        int i = 0;
        int j = s.size() - 1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
