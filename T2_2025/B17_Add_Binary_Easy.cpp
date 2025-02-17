// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string res = "";
//         int n = a.length();
//         int m = b.length();
//         if(n < m) {
//             int temp = n;
//             n = m;
//             m = temp;
//             string temp1 = a;
//             a = b;
//             b = temp1;
//         }
//         int nho = 0;
//         int j = n - 1;
//         for(int i = m - 1; i >= 0; i--) {
//             int temp = nho + a[j] - '0' + b[i] - '0';
//             nho = temp >= 2 ? 1 : 0;
//             // cout << a[i] << " " << b[i] << " " << temp << " " << nho << "\n";
//             res = to_string(temp%2) + res;
//             j--;
//         }
//         for(int i = n-m-1; i >= 0; i--) {
//             int temp = nho + a[i] - '0';
//             nho = temp >= 2 ? 1 : 0;
//             cout << temp << " " << nho << "\n";
//             res = to_string(temp%2) + res;
//         }
//         if(nho) res = "1" + res;

//         return res;
//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {
        int leading_zero_count = std::abs((int) (a.size() - b.size()));
        if(a.size() > b.size()){
            b.insert(0, leading_zero_count, '0');
        } else {
            a.insert(0, leading_zero_count, '0');
        }
        int carry = 0;
        string sum = "";
        for(int i = a.size() - 1; i>=0; i--){
            if(a[i] == b[i]){
                if(carry){
                    sum.insert(0, 1, '1');
                    carry = 0;    
                } else {
                    sum.insert(0, 1, '0');
                }
                if(a[i] == '1'){
                    carry = 1;
                }
            } else {
                if(carry){
                    sum.insert(0, 1, '0');
                    carry = 1;    
                } else {
                    sum.insert(0, 1, '1');
                }
            }
        }
        if(carry){
            sum.insert(0, 1, '1');
            carry = 1;    
        }
        return sum;
        
    }
};
