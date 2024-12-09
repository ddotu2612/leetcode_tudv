class Solution {
public:
    int expand_around_center(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right -left -1;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;

        for(int i = 0; i < s.size(); i++) {
            int old = expand_around_center(s, i, i);
            int even = expand_around_center(s, i, i+1);
            int max_len = max(old, even);
            if(max_len > end - start) {
                start = i - (max_len - 1)/2;
                end = i + max_len/2;
                cout << start << " " << end;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
