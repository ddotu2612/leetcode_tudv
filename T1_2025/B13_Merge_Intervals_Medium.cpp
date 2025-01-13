// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](vector<int> a , vector<int> b) {
//             return a[0] < b[0];
//         });

//         vector<vector<int>> res;
//         int pre0 = intervals[0][0];
//         int pre1 = intervals[0][1];
//         for(int i = 1; i < intervals.size(); i++) {
//             int a = intervals[i][0];
//             int b = intervals[i][1];
//             if(a >= pre0 && a <= pre1 && pre1 <= b) {
//                 pre1 = b;
//             } else if(a > pre1) {
//                 vector<int> v = {pre0, pre1};
//                 res.push_back(v);
//                 pre0 = a;
//                 pre1 = b;
//             }
//         }
//         vector<int> v = {pre0, pre1};
//         res.push_back(v);

//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);

            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }

        return ans;

    }
};
