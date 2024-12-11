class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        int res[101];
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) res[i] = nums[i];
            else if(nums[i] > 0) {
                res[i] = nums[(i + nums[i]%n) % n];
            } else {
                res[i] = nums[(i - abs(nums[i])%n + n) % n];
            }
        }
        vector<int> result;
        for(int i = 0; i < n; i++) {
            result.push_back(res[i]);
        }
        return result;
    }
};
