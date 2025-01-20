// class Solution {
// public:
//     string simplifyPath(string path) {
//         if(path == "/") return "/";
//         string res = "";
//         if(path[0] == '/') res += "/";
//         string c1 = "";
//         for(int i = 1; i < path.length(); i++) {
//             if(path[i] == '/' && path[i-1] == '/') continue;
//             // if(i == path.length() - 1 && path[i] == '/') continue;
//             c1 += path[i];
//         }
//         if(c1.length() > 0 && c1[c1.length()-1] != '/') c1 += "/";
//         cout << "c1: " << c1 << "\n";
//         string c2 = "";
//         for(int i = 0; i < c1.length(); i++) {
//             if(c1[i] == '/') {
//                 if(c2 == "..") {
//                     if(res.length() > 1) {
//                         int n = res.length()-1;
//                         while(res[n] == '/') {
//                             res.erase(n);
//                             n--;
//                         }
//                         n = res.length() - 1;
//                         while(res[n] != '/') {
//                             res.erase(n);
//                             n--;
//                         }
//                     }
//                 } else if(c2 != ".") {
//                     res += c2;
//                     res += "/";
//                 }
//                 cout << "res: " << res << "; c2: " << c2 << "\n";
//                 c2 = "";
//             } else {
//                 c2 += c1[i];
//             }
//         }
//         cout << res << "\n";
//         if(res.length() > 1 && res[res.length()-1] == '/') {
//             int n = res.length()-1;
//             cout << n << "\n";
//             while(res[n] == '/' && n > 0) {
//                 res.erase(n);
//                 n--;
//             }
//         }
//         cout << res << "\n";
//         return res;
//     }
// };

// C2:
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string> s;
        while(getline(ss, token, '/')) {
            if(token == "" || token == ".") {
                continue;
            } else if(token == "..") {
                if(!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(token);
            }
        }
        string res = "";
        while(!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res == "" ? "/" : res;
    }
};
