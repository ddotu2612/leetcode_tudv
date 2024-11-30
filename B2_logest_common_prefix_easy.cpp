class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string prefix = "";
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        for(int i = 0; i < min(first.size(), last.size()); i++) {
            if(first[i] != last[i]) return prefix;
            else prefix = prefix + first[i];
        }
        return prefix;
    }
};
