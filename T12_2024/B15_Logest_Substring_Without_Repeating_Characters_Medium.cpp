class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        int idx = 0;
        unordered_map<char, int> seen;
        for(int i = 0; i < n; i++) {
            char currentChar = s[i];
            if(seen.count(currentChar)) {
                idx = max(idx, seen[currentChar] + 1);
            }
            seen[currentChar] = i;
            res = max(res, i - idx + 1);
        }

        return res;
    }
};
