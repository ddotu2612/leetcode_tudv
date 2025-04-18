class Solution {
public:
    bool visited[7];
    void TRY(int k, vector<int>& nums, vector<vector<int>>& res, vector<int>& comb) {
        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                comb.push_back(nums[i]);
                visited[i] = true;
                if(k == nums.size() - 1) {
                    res.push_back(comb);
                }
                TRY(k + 1, nums, res, comb);
                visited[i] = false;
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        TRY(0, nums, res, comb);
        return res;
    }
};

// C2:

