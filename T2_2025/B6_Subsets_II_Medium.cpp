class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> comb;
        Try(0, nums, res, comb);
        return res;
    }

    void Try(int i, vector<int> nums, vector<vector<int>>& res, vector<int>& comb) {
        res.push_back(comb);
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]) continue;
            comb.push_back(nums[j]);
            Try(j + 1, nums, res, comb);
            comb.pop_back();
        }
    }
};
