class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> res;
        while(left <= right) {
            int mid = (right + left) / 2;
            if(nums[mid] == target) {
                while(nums[left] != target) left++;
                while(nums[right] != target) right--;
                res.push_back(left);
                res.push_back(right);
                return res;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        res.push_back(-1); res.push_back(-1);
        return res;
    }
};
