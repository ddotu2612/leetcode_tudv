// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<string> cstrs;
//         for(int i = 0; i < strs.size(); i++) {
//             cstrs.push_back(strs[i]);
//         }
//         for(int i = 0; i < strs.size(); i++) {
//             sort(cstrs[i].begin(), cstrs[i].end());
//             cout << cstrs[i] << " ";
//         }
//         map<string, vector<int>> m;
//         for(int i = 0; i < cstrs.size(); i++) {
//             m[cstrs[i]].push_back(i);
//         }
//         vector<vector<string>> res;
//         for(auto x: m) {
//             vector<string> s;
//             for(int i = 0; i < x.second.size(); i++){
//                 s.push_back(strs[x.second[i]]);
//             }
//             res.push_back(s);
//         }

//         return res;
//     }
// };

//C2:
 class Solution {
    unordered_map<string, vector<string>> anagrams;

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        for (auto str: strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].emplace_back(str);
        }

        // ans.reserve(anagrams.size());
        for (auto &[key, value]: anagrams)
            ans.push_back(std::move(value));

        return ans;
    }
};
