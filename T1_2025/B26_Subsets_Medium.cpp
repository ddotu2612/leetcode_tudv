class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> comb;
        Try(0, nums, comb, res);
        return res;
    }

    void Try(int start, vector<int> nums, vector<int>& comb, vector<vector<int>>& res) {
        res.push_back(comb);
        for(int i = start; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            Try(i + 1, nums, comb, res);
            comb.pop_back();
        }
    }
};
