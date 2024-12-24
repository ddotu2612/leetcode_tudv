class Solution {
public:
    string RLE(string s) {
        string temp="";
        int freq=1;
        for(int i=1;i<=s.size();i++){
            if( i<s.size() && s[i]==s[i-1] ){
                freq++;
            }
            else{
                temp+=to_string(freq);
                temp+=s[i-1];
                freq=1;
            }
        }
        return temp;
    }
    string countAndSay(int n) {
        string start = "1";
        for(int i = 1; i < n; i++) {
            start = RLE(start);
        }
        return start;
    }
};

