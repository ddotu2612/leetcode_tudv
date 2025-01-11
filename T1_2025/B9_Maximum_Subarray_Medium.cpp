class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumM = nums[0];
        int maxi1 = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(maxi1 + nums[i] > nums[i]) maxi1 = maxi1 + nums[i];
            else maxi1 = nums[i];
            sumM = max(sumM, maxi1);
        }
        return sumM;
    }
};
