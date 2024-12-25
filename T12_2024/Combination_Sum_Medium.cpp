class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        makeCombination(candidates, 0, 0, target, comb, res);
        return res;
    }

    void makeCombination(vector<int>& candidates, int idx, int sum, int target, vector<int>& comb, vector<vector<int>>& res) {
        if(sum > target || idx >= candidates.size()) return;
        if(sum == target) {
            res.push_back(comb);
            return;
        }
        comb.push_back(candidates[idx]);
        makeCombination(candidates, idx, sum + candidates[idx], target, comb, res);
        comb.pop_back();
        makeCombination(candidates, idx + 1, sum, target, comb, res);
    }
};
