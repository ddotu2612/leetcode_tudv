// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < nums.size(); i = i + 2) {
//             if(i == nums.size() || nums.size() == 1) return nums[i];
//             if(nums[i] != nums[i+1]) {
//                 return nums[i];
//             }
//         }
//         return 1;
//     }
// };


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo = 0;
        for(int i=0;i<nums.size();i++) {
            xo = xo ^ nums[i];
        }
        return xo;
    }
};
