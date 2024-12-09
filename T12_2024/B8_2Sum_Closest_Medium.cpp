class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min = INT_MAX / 2;
        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                int sum3 = nums[i] + nums[left] + nums[right];
                if(sum3 < target) {
                    left++;
                } else if(sum3 > target) {
                    right--;
                } else {
                    return sum3;
                }
                if(abs(sum3 - target) < abs(min - target)) {
                    min = sum3;
                }
            }
        }
        return min;
    }
};
