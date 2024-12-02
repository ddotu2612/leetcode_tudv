class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // solution 1: 312/313 testcase
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // vector<vector<int>> res;
    
        // // if(nums[0] == 0 && nums[n-1] == 0) {
        // //     vector<int> v = {0, 0, 0};
        // //     res.push_back(v);
        // //     return res;
        // // }
        // set<tuple<int, int, int>> s;
        
        // for(int i = 0; i < n - 2; i++) {
        //     int a = nums[i];
        //     int S = 0-a;
        //     map<int, int> m;
        //     // m[S - nums[i+1]] = i + 1;
        //     for(int j = i + 1; j < n; j++) {
        //         if(m[nums[j]] != NULL) {
        //             s.insert(make_tuple(nums[i], nums[m[nums[j]]], nums[j]));
        //         }
        //         else m[S - nums[j]] = j;
        //     }
        // }
        // for(auto t: s) {
        //     vector<int> v = {get<0>(t), get<1>(t), get<2>(t)};
        //     res.push_back(v);
        // }

        // return res;


        // Solution 2
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for(int i = 0; i < n ; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if(nums[i] + nums[j] + nums[k] > 0) k -= 1;
                else if(nums[i] + nums[j] + nums[k] < 0) j += 1;
                else {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    res.push_back(v);
                    j += 1;
                    while(nums[j] == nums[j-1] && j < k) j += 1;
                }
            }
        }

        return res;
    }
};
